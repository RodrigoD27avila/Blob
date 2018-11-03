; a
(display
(car (car '((a b) (c d))))
)
(newline)

; b
(display
(car (cdr (car '((a b) (c d)))))
)
(newline)

; c
(display
(car (car (cdr '((a b) (c d)))))
)
(newline)

; d
(display
(car (cdr (car (cdr '((a b) (c d))))))
)
(newline)
