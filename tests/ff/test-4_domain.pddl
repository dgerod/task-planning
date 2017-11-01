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
    :parameters (?p - container ?o - object)
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

(:action pickup_object
    :parameters (?p - container ?o - object)
    :precondition
        (and (robot-at ?p)
                (localised ?o)
                (object-at ?o ?p)
                (not(grasped ?o)))
    :effect
        (and (not (object-at ?o ?p))
                (grasped ?o))
)

(:action drop_object
    :parameters (?p - box ?o - object)
    :precondition
        (and (robot-at ?p)
                (grasped ?o))
    :effect
        (and (not(grasped ?o))
                (object-at ?o ?p))
)
)
