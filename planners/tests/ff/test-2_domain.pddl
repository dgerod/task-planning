(define (domain organize_boxes)
(:requirements :strips :typing :negative-preconditions :disjunctive-preconditions)

(:types
    place 
    object - place
    container - object
    videotape - object
    box - container
)

(:predicates
    (robot-at ?p - place)
    (object-at ?o - object ?p - place)
    (localised ?o - object)
    (grasped ?o - object)
)

(:action find_object
    :parameters (?o - object ?p - container)
    :precondition
        (and (robot-at ?p)
                (not (localised ?o)))
    :effect
        (and (localised ?o)
                (object-at ?o ?p))
)

(:action goto_place
    :parameters (?p - place)
    :effect
        (and (robot-at ?p))
)

)
