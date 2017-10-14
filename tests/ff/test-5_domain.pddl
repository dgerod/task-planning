(define (domain organize_boxes)
(:requirements :strips :typing :equality :negative-preconditions :disjunctive-preconditions :conditional-effects)

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

(:action goto_place
    :parameters (?p - place)
    :effect
        (and (robot-at ?p))
)
)
