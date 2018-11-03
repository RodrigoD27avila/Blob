#!/usr/bin/csi -ns
;a # (car . cdr)
(display (cons 'car 'cdr))
(newline)

;b # (this (is silly)
(display (list 'this '(is silly)))
(newline)

;c # (is this silly)
(display (cons 'is '(this silly)))
(newline)

;d # (+ 2 3)
(display (quote (+ 2 3)))
(newline)

;e # (+ 2 3)
(display (cons '+ '(2 3)))
(newline)

;f # +
(display (car '(+ 2 3)))
(newline)

;g # (2 3)
(display (cdr '(+ 2 3)))
(newline)

;h # #<procedure ...>
(display cons)
(newline)

;i # cons
(display (quote cons))
(newline)

;j # (quote cons)
(display (quote (quote cons)))
(newline)

;k # quote
(display (car (quote (quote cons))))
(newline)

;l # 5
(display (+ 2 3))
(newline)

;m # 5
(display (+ '2 '3))
(newline)

;n # 5
(display (+ (car '(2 3)) (car (cdr '(2 3)))))
(newline)

;o # 5
(display ((car (list + - * / )) 2 3))
(newline)
