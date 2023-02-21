#include <iostream>
using namespace std;

template <typename T>
int size_in_bits(const T &a)
{
    return sizeof(a) * 8;
}

int main()
{
    cout << size_in_bits(21) << endl;
    cout << size_in_bits('f') << endl;
    cout << size_in_bits(32.1f) << endl;
    cout << size_in_bits(32.1) << endl;
    return 0;
}

/*
1. Containers -> Array-like data structures that store collections of data like vectors, stack and queues
2. iterators -> These are pointer-like objects that allow traversal of containers generically.
3. algorithms -> a collection of functions for operations, such as search and sort and contained in the header file <algorithm>.
4. Functors or function components -> classes that overloads the parenthesis operator so that they can be used as functions that maintains state and can be parametarized <functional.h>

Container classes:
1. Sequence -> storage of data elements eg Vectors, List, Deques, Stacks, Queues
2. Associative -> Storage of associative pairs implemented as trees eg Sets, Maps, Multisets, Multimaps. elements are addressed by their content as opposed to being addressed by their location or index.
2 Categories of associative containers
 - associative containers
3 - Unordered Associative containers
 Storage of asociative pairs implemented as hash tables

Main Difference : associative are implemented with binary trees under the hood meaning they can be traversed, iterated through in a predictable order and are relatively fast to read or write
whereas
the unordered variants are implemented with hash tables so they are even faster on average but they have a very bad worse case performance.


SEQUENCE CONTAINERS
1. Vector is a dynamic sequence container -  it supports random access to insert and delete elements or to read and write.
Elements are stored contiguously in memory
Pointers may be used to iterate through the elements
vector resize dynamically upon insertions and deletions
and it performs reallocation automatically as needed
2. A List is a C++ STL implementation of a doubly linked list -> it does not support random access to insert or delete elements because being a linked list, it requires sequential access.
Elements are not stored contiguously in memory for the same reason. List are not inferior in performance when compared to a vector, they are just different.Insertion and deletion is cheaper if you use a list rather than a vector.
Bcos of unique advantages of singly-linked list, there's a container called forward_list since C++11
3. Deque is a C++ STL implementation of double ended queue. It supports push and pop operations on both ends. It also supports random access incase you need it even though a deque doesn't need random access.
Elements are not all stored contiguously in memory. It's actually implemented as chunks of contiguous data so in terms of performance, deque has something between the performance of a vector and that of list .
a deque implements the behaviour of more modest data structures such as a stack or a queue. It's a container adapter.
Container adapters are interfaces that implement some special functionality on top of a sequence container - C++11 supports the ff container adapters ->
a. Stack - which implements  push and pop operations on one end.
b. Queue - which implements push on one end to enque and pop on the other end to dequeue.
c. priority queue -> which is a data structure that supports the operations of a queue but always dequeue the max element.
This is naturally performed by an array based data structure called a heap, thus it's underlying container is usually a vector but it could also be a deque.
All of these options underlying container options are possible because container adapters are templates too so Generic programming allows all of these flexibilities.

ASSOCIATIVE CONTAINERS
Since we  only care about the logical operations rather than the implementations of these containers, the ff explanations apply to both ordered associative and unorodered associative containers.
1. A Set is a model of a mathematical set which is a colleciton of unique elements that serve as keys. This means that if you select some elements twice, the set will not change the second time because it has an element with that key and value. There are 4 variants of sets which comes from 2 aspects:
- a- Sets can be ordered or unordered. Ordered sets are implemented as binary trees whereas Unordered sets are implemented as hash tables
- b- The second aspect is whether you want to support duplicate elements. If so, you'll have to use a Multiset or a bag as it is also known in discrete mathematics. Due to this variation, there are 4 types of set implementations in the C++ STL.
i. Regular Set
ii. Regular Multiset
iii. Unordered Set
iv. Unordered Multiset

2. Maps - is a set of pairs
Pairs are special struct templates that implement the storage of two different class objects or what is known as a two tuple. These two elements of a pair are called first and second. An STL Map resembles a set in many ways because it's a special case of it, a set of pairs, where the key is the first element of the pair. Just like sets, there are the same four variations of maps. So, ordered maps are implemented as binary trees and unordered maps as hash tables. also for duplicate keys, you can use a multimap

ITERATORS
Iterators are objects that enable us to traverse containers in some order for either reading or writing.
Iterators in the C++ STL are defined as templates and they must comply with a very specific set of rules in order to qualify as one of many types of iterators.
Are pointers and iterators the same thing???
No, pointers are variables that may refer to some memory location. A pointer however, meets the requirements for many types of iterators so a pointer is a type of iterator. integers also qualify as iterators.
So in short, an iterator is a higher abstraction for an element used to travese containers, whereas pointers and integers are special types of iterators not suitable for every container out there.
An iterator is an abstract concept that comes down to a series of requirements for an object to qualify as so. The C++ STL defines five to increasingly capable types of iterators,
i. input iterator
ii. output itertor
iii. forward iterator
iv. bidirectional iterator
v. random access iterator
All containers require these iterators to comply with the capabilities of some of these types.

i. Input iterator -> required to read forward. It onlysupports one pass of the container meaning that if you try to go through the container twice, you may get different results the second time
suitable for input streams such as keyboard buffers or read only files which are all available in the STL.
ii. Output iterator -> it is used for writing instead of reading. it also works only to trac=verse the container forward and only support one pass. it's suitable for output streams such as text output or write-only files.
iii. A Forward iterator has the requirement of both the input and the output iterator. it is required to be able to read and write. In fact, starting with the forward iterator,  all are capable of reading and writing. [mutable iterators are only capable of writing]. also required to support multiple passes of the container. A forward iterator is suitable for a singly linked list
iv. Bidorectional iterators are required  to support all the capabilities of forward iterators plus backward traversal. this iterator is useful for doubly linked lists.
v. Random Access Iterator is the most capable of all, required to support all of the features od the bidirectional iterator plus random access by means of indexing. This itertor is suitable for vectors and similar containers.

Iterator          Containers
Forward           forward_list, unordered_[multi]set,           unordered_[multi]map
Bidirectional     list, [multi]set, [multi]map
Random Access       vector, deque, array

FOUR IMPORTANT ITERATOR FUNCTIONS
begin() -> returns an iterator to the begining of the container
end() -> returns an iterator to the end of the container
rbegin() -> returns a reverse iterator to the reverse begining of the container which is the first element of the reverse container.
rend() -> returns a reverse iterator to the reverse end of the container

Iterator help keeping access to containers generic, so they're very useful for producing flexible code. However, there is a big problem you must be aware of, and that' iterator invalidtion.
When there are changes, such as an insertions or deletions in containers that are currently using iterators, these iterators may become invalid. by this it is not guarantedd that the iterator has the same acces to the container it was referring to before the change.
*/