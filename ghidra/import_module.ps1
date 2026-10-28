# Import one decrypted module into a private Ghidra project (projects/<slug>) with the Allegrex processor and run
# auto-analysis, for the advisory pseudocode export (run_commit_decompile.ps1). Machine paths come from
# lbp-config.json (ghidra_headless, java_home, ghidra_allegrex) or LBP_<KEY>. The ghidra-allegrex extension is copied
# once from -ExtensionSource (default: the ghidra_allegrex setting) into this repository's gitignored ghidra/settings/.
#   pwsh -NoProfile -File ghidra/import_module.ps1 -Slug EBOOT_BIN -Module <decrypted module path>
param(
    [Parameter(Mandatory = $true)][string]$Slug,
    [Parameter(Mandatory = $true)][string]$Module,
    [string]$Processor = 'Allegrex:LE:32:default',
    [string]$ExtensionSource = ''
)
$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent $PSScriptRoot
function Get-LbpSetting([string]$Key) {
    $value = [Environment]::GetEnvironmentVariable('LBP_' + $Key.ToUpper())
    if (-not $value) {
        $file = Join-Path $repo 'lbp-config.json'
        if (Test-Path -LiteralPath $file) { $value = (Get-Content -LiteralPath $file -Raw -Encoding UTF8 | ConvertFrom-Json).$Key }
    }
    if (-not $value) { throw "lbp-config: setting '$Key' is not set (lbp-config.json or LBP_$($Key.ToUpper()))." }
    $value
}
$headless = Get-LbpSetting 'ghidra_headless'
$env:JAVA_HOME = Get-LbpSetting 'java_home'
$root = $PSScriptRoot
$settings = Join-Path $root 'settings'
$cache = Join-Path $root 'cache'
$ext = Join-Path $settings ($env:USERNAME + '-ghidra\ghidra_12.1.4_PUBLIC\Extensions\ghidra-allegrex')
if (-not (Test-Path -LiteralPath $ext)) {
    if (-not $ExtensionSource) { $ExtensionSource = Get-LbpSetting 'ghidra_allegrex' }
    $null = New-Item -ItemType Directory -Force -Path (Split-Path -Parent $ext)
    Copy-Item -Recurse -LiteralPath $ExtensionSource -Destination $ext
}
$env:GHIDRA_HEADLESS_JAVA_OPTIONS = '-Duser.home=' + (Join-Path $settings $env:USERNAME) + ' -Dapplication.settingsdir=' + $settings + ' -Dapplication.cachedir=' + $cache
$project = Join-Path $root ('projects\' + $Slug)
if (Test-Path -LiteralPath $project) { throw "project exists: $project" }
$null = New-Item -ItemType Directory -Force -Path $project
$log = Join-Path $project 'import.log'
& $headless $project ('PSPCandidate_' + $Slug) -import $Module -processor $Processor -max-cpu 8 2>&1 | Set-Content -LiteralPath $log -Encoding UTF8
"EXIT=$LASTEXITCODE"
Get-Content -LiteralPath $log | Select-String 'ERROR|Exception|Import succeeded|ANALYZING|REPORT' | Select-Object -First 20
