package main

import (
	"fmt"
)

type Dll struct {

	Data interface{}
	Prev *Dll
	Next *Dll 
}

func (l *Dll) insert(data int) (* Dll){

	n := new (Dll)
	n.Prev = nil
	n.Next = nil
	n.Data = data

	if (l == nil) {
		/* first element */
		l = n
	} else {

		l.Prev = n
		n.Next=l
		l = n

	}

	return n

}

func (l *Dll)display ()  {
    
	fmt.Println ("Displaying ...") 
	

	for {
      if l != nil {
		fmt.Println (l.Data)  
        l = l.Next
	   } else {
		   break
	   }
	} 	    
}

func (l *Dll) delete (element int)(* Dll){

	fmt.Printf ("Deleteing ... %d \n", element) 

	m := l
	

	found := 0
	
    // check if the element exists
	for {
      if l != nil {
		     
		if l.Data == element {
			found = 1
			break
		}
		
        l = l.Next

	   } else {
		   break
	   }
	} 
	
	if found == 1 {

		if l.Prev == nil {
			/* deleting the first element */
			return l.Next
		} else {
			l.Prev.Next = l.Next
			l.Next.Prev = l.Prev
			return m
		}

	} else {

		fmt.Println ("No elements found")
		return m
	}



}

func main () {

	fmt.Println ("Imnplementing double linklist")

	var root *Dll = nil

	root = root.insert(10)
	root = root.insert(100)
	root = root.insert(200)
	root = root.insert(30)
	root = root.insert(90)

	root.display()

	root = root.delete(200)

	root.display()

	root = root.delete(90)

	root.display()
 }