;; hypothesis F-load3-st3
(define_automaton "allegrex_mem")
(define_cpu_unit "alg_mem" "allegrex_mem")
(define_insn_reservation "alg_load" 3
  (and (eq_attr "cpu" "allegrex") (eq_attr "type" "load,fpload,fpidxload"))
  "alu+alg_mem")
(define_insn_reservation "alg_store" 1
  (and (eq_attr "cpu" "allegrex") (eq_attr "type" "store,fpstore,fpidxstore"))
  "alu+alg_mem,alg_mem*2")
