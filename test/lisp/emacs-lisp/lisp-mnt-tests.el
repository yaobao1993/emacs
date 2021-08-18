;;; lisp-mnt-tests.el --- Tests for lisp-mnt  -*- lexical-binding: t; -*-

;; Copyright (C) 2021  2020-2021 Free Software Foundation, Inc.

;; Author: Stefan Monnier <monnier@iro.umontreal.ca>

;; This program is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation, either version 3 of the License, or
;; (at your option) any later version.

;; This program is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with this program.  If not, see <https://www.gnu.org/licenses/>.

;;; Commentary:

;;

;;; Code:

(require 'ert)
(require 'lisp-mnt)

(ert-deftest lm--tests-crack-address ()
  (should (equal (lm-crack-address
                  "Bob Weiner <rsw@gnu.org>, Mats Lidell <matsl@gnu.org>")
                 '(("Bob Weiner" . "rsw@gnu.org")
                   ("Mats Lidell" . "matsl@gnu.org")))))

(provide 'lisp-mnt-tests)
;;; lisp-mnt-tests.el ends here