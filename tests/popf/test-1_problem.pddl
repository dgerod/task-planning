(define (problem organize_boxes_task)
(:domain organize_boxes)
(:objects
    c1 - container
    b1 b2 - box
    v1 v2 - videotape
    v3 v4 - videotape
)
(:init
 	(not (grasped v1))
)
(:goal (and
    (robot-at c1)
))
)
