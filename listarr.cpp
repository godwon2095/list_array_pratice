//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------


#include "listarr.hpp"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

: maxSize(maxNumber),
size(0),
cursor(-1)
{
    // pre-lab
    dataItems = new DataType(maxNumber);
}

//--------------------------------------------------------------------

List:: ~List()

// Frees the memory used by a list.

{
    delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType &newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
    // pre-lab
    // isFull함수를 사용하여 list가 비어있는지 검사한 후
    // list가 비어있는경우와 비어있지않은 경우를 나누어
    // 입력받은 데이터를 저장해준다.
    // 데이터 저장은 cursor위치의 다음부터 저장을 한다.
    if (!List::isFull())
    {
        if (List::isEmpty())
        {
            dataItems[size] = newDataItem;
            cursor = size;
            size++;
        }
        else if (!List::isEmpty())
        {
            if ((size - cursor) == 1)
            {
                dataItems[size] = newDataItem;
                cursor = size;
                size++;
            }
            else if (!((size - cursor) == 1))
            {
                dataItems[size] = dataItems[cursor + 1];
                dataItems[size - 1] = newDataItem;
                cursor++;
                size++;
            }
        }
    }
    else
        cout << "List is Fulled" << endl;
}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.

{
    // pre-lab
    // list가 비어있는지 검사한 후 size와 cursor의 관계를 이용해
    // 데이터를 자리바꿈을 해주고 size를 조절한다.
    if (!List::isEmpty())
    {
        if ((size - cursor) > 1)
        {
            int i = 0, j = cursor;
            for (i = cursor; i <= size - cursor; i++)
            {
                dataItems[cursor] = dataItems[cursor + 1];
                cursor++;
            }
            cursor = j;
            size--;
        }
        else if ((size - cursor) == 1)
        {
            size--;
            cursor = 0;
        }
    }
    else
        cout << "List is Empty" << endl;
}

//--------------------------------------------------------------------

void List::replace(const DataType &newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
    // Requires that the list is not empty
    // pre-lab
    // list가 비어있는지를 검사한 후
    // cursor가 가르키는 자리에 새로 입력받은 데이터를 저장한다.
    if (!List::isEmpty())
    {
        dataItems[cursor] = newDataItem;
    }
}

//--------------------------------------------------------------------

void List::clear()

// Removes all the data items from a list.

{
    // pre-lab
    // size와 list를 초기설정값으로 바꾸어준다.
    size = 0;
    cursor = -1;
}

//--------------------------------------------------------------------

bool List::isEmpty() const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
    // pre-lab
    // size가 0일 경우 1을 반환하고 아닐경우 0을 반환한다.
    if (size == 0)
        return true;
    else
        return false;
}

//--------------------------------------------------------------------

bool List::isFull() const

// Returns 1 if a list is full. Otherwise, returns 0.

{
    // pre-lab
    // size가 maxSize일 경우 1을 반환하고 아닐경우 0을 반환한다.
    if (size == maxSize)
        return true;
    else
        return false;
}

//--------------------------------------------------------------------

int List::gotoBeginning() throw (logic_error)

// Moves the cursor to the beginning of the list.

{
    // pre-lab
    // list가 비어있는지 검사한 후 비어있지 않다면
    // cursor를 list의 가장 처음 값으로 보낸다.
    if (!List::isEmpty())
    {
        cursor = 0;
        return 1;
    }
    else
        return 0;
}



//--------------------------------------------------------------------

int List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
    // pre-lab
    // list가 비어있는지 검사한 후 비어있지 않다면
    // cursor를 가장 마지막 값으로 보낸다.
    if (!List::isEmpty())
    {
        cursor = size - 1;
        return 1;
    }
    else
        return 0;
}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.

{
    // pre-lab
    // cursor가 가장 마지막 데이터를 가르키고있는지 검사한 후
    // 그렇지 않다면 cursor를 다음 데이터를 지정하도록 한다.
    if (!(cursor == size - 1))
    {
        cursor++;
        return true;
    }
    else
        return false;
}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
    // pre-lab
    // cursor가 초기값을 가르키고있는지 검사한 후
    // 그렇지 않다면 cursor를 이전값을 지정하도록 한다.
    if (!(cursor == 0))
    {
        cursor--;
        return true;
    }
    else
        return false;
}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error)

// Returns the item marked by the cursor.

{
    // pre-lab
    // cursor가 위치하고 있는 값을 반환한다.
    if (!List::isEmpty()) {
        return dataItems[cursor];
    }
    return 0;
};

//--------------------------------------------------------------------

void List::showStructure() const

// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
    // pre-lab
    // list가 비어있는지 검사한 후 비어있지 않다면
    // size와 cursor의 위치, 반복문을 사용하여 저장된 데이터를 출력한다.
    if (!List::isEmpty())
    {
        cout << "size of List: " << size << endl;
        cout << "location of cursor: " << cursor << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << "-data: " << dataItems[i] << endl;
        }
    }
    else
        cout << "Empty List" << endl;
}

void List::search(const DataType &Item) throw (logic_error) {
    
    // 먼저 비어있는지 검사 하고
    // 비어있지 않으면 해당 커서 위치를 기준으로 오른쪽 탐색을 실행한다
    // 해당 원소가 있으면 성공 메시지, 커서를 해당 위치로 이동하며 함수를 종료하고
    // 그렇지 않은경우 실패했다는 메시지를 띄워준다
    if (!List::isEmpty()) {
        for (int i = cursor; i < size; i++) {
            if (Item == dataItems[i]) {
                cout << "Search succeeds" << endl;
                cursor = i;
                return;
            }
        }
        cout << "Searcch fails" << endl;
    }
    else {
        cout << "List is empty" << endl;
    }
}
