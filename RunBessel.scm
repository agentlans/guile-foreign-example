;; https://www.gnu.org/software/guile/manual/html_node/A-Sample-Guile-Extension.html

;; First, run this in Bash so Guile can find the library
;;   export LTDL_LIBRARY_PATH=.

(load-extension "libguile-bessel" "init_bessel")

;; Test the Bessel function
(j0 2)

;; Test the foo struct defined in C
(define bar (make-foo 3.14))
(get-foo bar)


