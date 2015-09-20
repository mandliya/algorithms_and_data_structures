/**
 *  A linux kernel like implementation of double linked list.
 */

#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

struct list_head {
    struct list_head * next;
    struct list_head * prev;
};

/**
 * Following two macros are for initializing an empty list.
 */
#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
        struct list_head name = LIST_HEAD(name)

static inline void INIT_LIST_HEAD( struct list_head * list )
{
    list->next = list;
    list->prev = list;
}

/**
 * Insert a new entry between two known consecutive entries.
 * This is for internal use only as we know consecutive list entries
 * and where we want to insert the newNode between prevNode and
 * nextNode in list
 */

static inline void __list_add( struct list_head *newNode,
                               struct list_head *prevNode,
                               struct list_head *nextNode)
{
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;
}
/**
 * list_add - Add a new entry
 * @param  newNode [new entry to be added in list]
 * @param  head    [list head to add it after]
 * @return         [none]
 * Insert a new entry after specified head
 * This is good for implementation of a stack
 */
static inline void  list_add( struct list_head * newNode,
                              struct list_head * head)
{
    __list_add( newNode, head, head->next );
}

/**
 * list_add_tail [Add a new entry to the tail]
 * @param newNode [new entry to be added]
 * @param head    [list add to add it before]
 *
 * Insert a new entry before specified head
 * This is good for implementation of queue.
 */
static inline void list_add_tail( struct list_head * newNode,
                                  struct list_head * head)
{
    __list_add( newNode, head->prev, head );
}

/**
 * Delete an entry between prevNode and nextNode by making prevNode/nextNode
 * pointing to each other
 * This is only used for internal list manipulation when we
 * know prevNode/nextNode entries already
 */
static inline void __list_del( struct list_head * prevNode,
                               struct list_head * nextNode)
{
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

/**
 * Deletes an entry from the list
 * @param entry [Entry to be deleted]
 */
static inline void list_del( struct list_head * entry )
{
    __list_del(entry->prev, entry->next);
    entry->prev = nullptr;
    entry->next = nullptr;
}

static inline void __list_del_entry( struct list_head * entry) {
  __list_del( entry->prev, entry->next );
}

/**
 * Replace @oldNode with @newNode in the list
 * @param oldNode [Node to be replaced]
 * @param newNode [This node replaces the oldNode]
 */
static inline void list_replace( struct list_head * oldNode,
                                 struct list_head * newNode)
{
    newNode->next = oldNode->next;
    newNode->prev = oldNode->prev;
    oldNode->prev->next = newNode;
    oldNode->next->prev = newNode;
}

static inline void list_replace_init( struct list_head * oldList,
                                      struct list_head * newList)
{
    list_replace( oldList, newList );
    INIT_LIST_HEAD( oldList );
}


/**
 * Deletes the entry from the list and reinitialize it
 * @param entry [node to be deleted and reinitialized]
 */
static inline void list_del_init( struct list_head * entry )
{
    __list_del( entry->prev, entry->next );
    INIT_LIST_HEAD( entry );
}

/**
 * list_move - deletes from one list and adds as another's head
 * @param list [the entry to move]
 * @param head [the head that will precede our entry]
 */
static inline void list_move( struct list_head * list,
                              struct list_head * head)
{
    __list_del_entry( list );
    list_add( list, head );
}

/**
 * list_move_tail- deletes from one list and adds as another's tail
 * @param list [the entry to move]
 * @param head [the head that will follow our entry]
 */
static inline void list_move_tail( struct list_head * list,
                              struct list_head * head)
{
    __list_del_entry( list );
    list_add_tail( list, head );
}

/**
 * list_is_last - Determines if @entry node is the last in the list
 * @param  entry [Node to be checked if it is last]
 * @param  head  [the head of the list]
 * @return [ true if entry is last false otherwise]
 */
static inline bool list_is_last( const struct list_head * entry,
                                 const struct list_head * head )
{
    return ( entry->next == head );
}

/**
 * list_is_empty - Verifies if the list is empty
 * @param  head [the list to be tested`
 * @return - returns true if list is empty, otherwise false
 */
static inline bool list_is_empty( const struct list_head * head )
{
    return ( head->next == head );
}

/**
 * list_is_empty_careful - tests whether list is empty and not being modified i.e.
 * 									       checks that no other cpu is in process of modifying next or prev
 * @param  head [the list to be tested]
 * @return      [returns true if list is empty and not being modified]
 */
static inline bool list_is_empty_careful( const struct list_head * head)
{
    struct list_head * nextNode = head->next;
    return ( nextNode == head ) && ( nextNode == head->prev );
}


/**
 * list_rotate_left - Rotate the list to left (1,2,3,4)-->(2,3,4,1)
 * @param head head of the list
 */
static inline void list_rotate_left( struct list_head * head )
{
    struct list_head * first;
    if ( !list_is_empty(head) ) {
        first = head->next;
        list_move_tail( first, head );
    }
}

/**
 * [list_is_singular - check if list contain just one entry
 * @param  head [head of the list]
 * @return      [return true if list has just one entry false otherwise]
 */
static inline bool list_is_singular( const struct list_head * head)
{
  return (!list_is_empty(head) && ( head->next == head->prev ));
}


/**
 * Internal function to join two list at position between prev and next
 * @param list [new list]
 * @param prev [new list to be added after this]
 * @param next [new list to be added before this]
 */
static inline void __list_splice( const struct list_head * list,
                                  struct list_head * prev,
                                  struct list_head * next)
{
  struct list_head * first = list->next;
  struct list_head * last = list->prev;

  first->prev = prev;
  prev->next = first;

  last->next = next;
  next->prev = last;
}

/**
 * list-splice Join two lists
 * @param list [The new list to be added]
 * @param head [The entry where you want to add the new list in current list]
 */
static inline void list_splice( const struct list_head * list,
                                struct list_head * head )
{
  if( !list_is_empty(list) ) {
    __list_splice(list, head, head->next);
  }
}

/**
 * list_splice_init : join two lists and reinitialise the emptied list.
 * @param list [The new list to be adeed]
 * @param head [The entry where you want to add the new list in current list]
 */
static inline void list_splice_init( struct list_head * list,
                                     struct list_head * head)
{
  if( !list_is_empty(list) ) {
    __list_splice(list, head, head->next);
    INIT_LIST_HEAD(list);
  }
}

/**
 * list_entry - get the struct for this entry
 * @param  ptr     [the &struct list_head pointer]
 * @param  ptrtype [the pointer to the type of struct this was embedded in]
 * @param  member  [the name of the list_struct within the struct.]
 */
#define list_entry(ptr, ptrtype, member) \
  (reinterpret_cast<ptrtype>( (char *)(ptr) - (char *)(&(reinterpret_cast<ptrtype>(1)->member)) + 1))

/**
 * [list_for_each] -- Iterate over a list
 * @param  pos  [the &struct list_head to use as a loop counter.]
 * @param  head [the head for your list.]
 */
#define list_for_each(pos, head)          \
  for(pos = (head)->next; pos != (head);  \
      pos = pos->next)

/**
 * [list_for_each_prev] -- Iterate over a list in reverse
 * @param  pos  [the &struct list_head to use as a loop counter.]
 * @param  head [the head for your list.]
 */
#define list_for_each_prev(pos, head)     \
  for (pos = (head)->prev; pos != (head); \
       pos = pos->prev)

/**
 * list_for_each_safe	-	iterate over a list safe against removal of list entry
 * @pos:	the &struct list_head to use as a loop counter.
 * @n:		another &struct list_head to use as temporary storage
 * @head:	the head for your list.
 */
 #define list_for_each_safe(pos, n, head)                 \
  for (pos = (head)->next, n = pos->next; pos != (head);  \
       pos = n, n = pos->next)


/**
 * list_for_each_entry - iterate over a list of given type
 * @param  pos    [The pointer to use as loop counter]
 * @param  head   [The head of your list]
 * @param  member [the name of the list_struct within the struct.]
 */
 #define list_for_each_entry(pos, head, member)               \
  for (pos = list_entry((head)->next, decltype(pos), member);   \
       &pos->member != (head);                                \
       pos = list_entry(pos->member.next, decltype(pos), member))

/**
 * Move a node to the front
 */
static inline void list_mtf(struct list_head *entry, struct list_head *head) {
  if (entry->prev == head) return;
    __list_del(entry->prev, entry->next);
    __list_add(entry, head, head->next);
  }


/**
 * Move a node ahead one position
 */
static inline void list_mao(struct list_head *entry, struct list_head * head) {
  // if the entry in the 1st position
	if (entry->prev == head) return;
	 struct list_head * prev = entry->prev;
   __list_del(entry->prev, entry->next);
   __list_add(entry, prev->prev, prev);
}

#endif
