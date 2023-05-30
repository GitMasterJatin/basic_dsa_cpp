
void insertSorted( stack<int>& stk, int elem ){
    
    if( stk.empty() || ( !stk.empty() && stk.top() < elem ) ){
        stk.push(elem);
        return;
    }

    // pop until base condition is met. Similar to inserting in the middle;
    int n = stk.top();
    stk.pop();

    insertSorted(stk,elem);

    stk.push(n);

}

void sortStack( stack<int>& stk ){

    if( stk.empty() ){
        return;
    }

    int num = stk.top();
    stk.pop();

    sortStack( stk );

    // insert in sorted order while inserting back into the stack;
    // similar to insertion sort
    insertSorted( stk, num );

}
