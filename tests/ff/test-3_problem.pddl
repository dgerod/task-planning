(define (problem organize_boxes_task)
(:domain organize_boxes)
(:objects
    c1 - container
    b1 b2 - box
    v1 v2 - videotape
    v3 v4 - videotape
)
(:init
    (robot_at c1)
    (localised v1)
    (object_at v1 c1)
)
(:goal (and
    (grasped v1)
))
)
