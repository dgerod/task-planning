(define (domain organize_boxes)
(:requirements :strips :typing :disjunctive-preconditions)

(:types
    place
    object - place
    container - object
    videotape - object
    box - container
)

(:predicates
    (robot_at ?p - place)
    (object_at ?o - object ?p - place)
    (localised ?o - object)
    (grasped ?o - object)
)

(:action pickup_object
    :parameters (?p - container ?o - object)
    :precondition
        (and (robot_at ?p)
                (localised ?o)
                (object_at ?o ?p)
                (not(grasped ?o)))
    :effect
        (and (not (object_at ?o ?p))
                (grasped ?o))
)
)
