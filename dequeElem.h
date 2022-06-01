/**
 * @file dequeElem.h
 * @brief Defines the type DequeElem.
 * 
 * The DequeElem is an alias to the type of elements 
 * held by an instance of the ADT Deque (PtDeque).
 * 
 * This alias just be changed according to the use-case.
 * 
 * @author Bruno Silva (bruno.silva@estsetubal.ips.pt)
 * @bug No known bugs.
 */

#pragma once

/** Type definition. Change according to the use-case. */

typedef int DequeElem;

/**
 * @brief Prints an element.
 * 
 * Must be implemented according to type
 * of defined for DequeElem.
 * 
 * @param elem [in] element to print
 */
void dequeElemPrint(DequeElem elem);
