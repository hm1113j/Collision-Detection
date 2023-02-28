
(cl:in-package :asdf)

(defsystem "cluster_counter-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Fin" :depends-on ("_package_Fin"))
    (:file "_package_Fin" :depends-on ("_package"))
  ))