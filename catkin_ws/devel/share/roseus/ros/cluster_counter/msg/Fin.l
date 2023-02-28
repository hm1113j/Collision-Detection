;; Auto-generated. Do not edit!


(when (boundp 'cluster_counter::Fin)
  (if (not (find-package "CLUSTER_COUNTER"))
    (make-package "CLUSTER_COUNTER"))
  (shadow 'Fin (find-package "CLUSTER_COUNTER")))
(unless (find-package "CLUSTER_COUNTER::FIN")
  (make-package "CLUSTER_COUNTER::FIN"))

(in-package "ROS")
;;//! \htmlinclude Fin.msg.html


(defclass cluster_counter::Fin
  :super ros::object
  :slots (_num _aveD _minD _angle _size ))

(defmethod cluster_counter::Fin
  (:init
   (&key
    ((:num __num) 0)
    ((:aveD __aveD) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:minD __minD) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:angle __angle) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:size __size) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _num (round __num))
   (setq _aveD __aveD)
   (setq _minD __minD)
   (setq _angle __angle)
   (setq _size __size)
   self)
  (:num
   (&optional __num)
   (if __num (setq _num __num)) _num)
  (:aveD
   (&optional __aveD)
   (if __aveD (setq _aveD __aveD)) _aveD)
  (:minD
   (&optional __minD)
   (if __minD (setq _minD __minD)) _minD)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:size
   (&optional __size)
   (if __size (setq _size __size)) _size)
  (:serialization-length
   ()
   (+
    ;; int64 _num
    8
    ;; float64[] _aveD
    (* 8    (length _aveD)) 4
    ;; float64[] _minD
    (* 8    (length _minD)) 4
    ;; float64[] _angle
    (* 8    (length _angle)) 4
    ;; float64[] _size
    (* 8    (length _size)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _num
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _num (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _num) (= (length (_num . bv)) 2)) ;; bignum
              (write-long (ash (elt (_num . bv) 0) 0) s)
              (write-long (ash (elt (_num . bv) 1) -1) s))
             ((and (class _num) (= (length (_num . bv)) 1)) ;; big1
              (write-long (elt (_num . bv) 0) s)
              (write-long (if (>= _num 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _num s)(write-long (if (>= _num 0) 0 #xffffffff) s)))
     ;; float64[] _aveD
     (write-long (length _aveD) s)
     (dotimes (i (length _aveD))
       (sys::poke (elt _aveD i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _minD
     (write-long (length _minD) s)
     (dotimes (i (length _minD))
       (sys::poke (elt _minD i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _angle
     (write-long (length _angle) s)
     (dotimes (i (length _angle))
       (sys::poke (elt _angle i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _size
     (write-long (length _size) s)
     (dotimes (i (length _size))
       (sys::poke (elt _size i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _num
#+(or :alpha :irix6 :x86_64)
      (setf _num (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _num (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64[] _aveD
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _aveD (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _aveD i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _minD
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _minD (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _minD i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _angle
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _angle (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _angle i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _size
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _size (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _size i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get cluster_counter::Fin :md5sum-) "e9d0a7c59b5482a4d7136307a7022f4a")
(setf (get cluster_counter::Fin :datatype-) "cluster_counter/Fin")
(setf (get cluster_counter::Fin :definition-)
      "int64 num
float64[]  aveD
float64[]  minD
float64[]  angle
float64[]  size

")



(provide :cluster_counter/Fin "e9d0a7c59b5482a4d7136307a7022f4a")


