

package main

import (
	"fmt"
)

type stack_data struct {
     
	data int;
    next *stack_data

}


type  stack struct {

	data *stack_data 
}


func newStack () (*stack) {

	st := new(stack)
	st.data = nil

	return st

}

func (st *stack) push (element int) () {

	if (st == nil) {
		fmt.Println ("stack not initialize")
		return 
	}

	temp := new (stack_data)

	temp.data = element
	temp.next = nil

	if st.data == nil  {

		st.data  = temp
	    
	} else {
        
		temp.next = st.data
		st.data = temp

	}	

}

func (st *stack) pop () (int) {

	if (st == nil) {
		fmt.Println ("stack not initialize")
		return  -1
	}

	element  := -1

	if st.data == nil {

		fmt.Println ("empty stack")

	} else {

	   element = st.data.data 
	   st.data = st.data.next
	}   

	return element

}

func main () {

	fmt.Println ("stack using linklist")

	var st *stack = newStack () 

	st.push (10)

	fmt.Println (st.pop ())
	fmt.Println (st.pop ())

}