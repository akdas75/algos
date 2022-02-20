package main

import (
	"fmt"
)

type  List struct {

	 data interface{};
	 next *List

};

func (l *List)insert_node_tail (element int) (*List) {

	m := l
	s := new(List)
	s.data = element
	if l == nil {
		fmt.Println ("Nil pointer")
		
        return s
	} else {

		for {
            if m.next != nil {
               m = m.next
		    } else {
				break
			}
		} 

        m.next = s
		return l

	}	    
}

func (l *List)insert_node_head (element int) (*List) {

	
	s := new(List)
	s.data = element
	if l == nil {
		fmt.Println ("Nil pointer")
		
        return s
	} else {
		s.next=l
		return s
	}	    
}

func (l *List)display_list ()  {
    
	fmt.Println ("Displaying ...") 
	

	for {
      if l != nil {
		fmt.Println (l.data)  
        l = l.next
	   } else {
		   break
	   }
	} 	    
}

func (l *List)delete_node (element int)  (*List){
    
	fmt.Printf ("Deleteing ... %d \n", element) 

	m := l
	var prev *List = nil

	found := 0
	
    // check if the element exists
	for {
      if l != nil {
		
     
		if l.data == element {
			found = 1
			break
		}
		prev = l
        l = l.next

	   } else {
		   break
	   }
	} 
	
	if found == 1 {

		if prev == nil {
			/* deleting the first element */
			return l.next
		} else {
			prev.next = l.next
			return m
		}

	} else {

		fmt.Println ("No elements found")
		return m
	}
}

func (l *List) reverse_display () {

	if (l != nil) {
	    l.next.reverse_display()
		fmt.Println (l.data) 
	}	
		

}

func (l *List) reverse () (*List){

	var prev *List = nil
	var cur  *List = l
	var next *List = nil

	fmt.Println ("Reversing ....")

	for {

		if (cur == nil) {
             return prev
		} else {
             next = cur.next
			 cur.next = prev
			 prev = cur
			 cur = next
		}
	}	
		

}


func (l *List) insert_sorted (element int) (* List) {

    var prev *List = nil
	//var cur *List = l
	var root *List = l

	s := new (List)
    s.data = element
	s.next = nil

	fmt.Printf ("Inserting ....%d \n",element)

	if (l == nil) {		

		return s
	} else {

		for {

			
			if element < l.data.(int) {

				if prev == nil {
					/* First element */

					s.next = l
					return s

				} else {
                   
					prev.next = s
					s.next = l

					return root
				}
				

			} else {
				fmt.Printf ("TO next....\n")
				prev = l
				l = l.next

				if l == nil {
					/* reach last element */
					prev.next = s
					return root
				}
			} 

		}

	}

	
	
}

func main () {

	var root *List = nil

	root = root.insert_node_tail (5)
	root = root.insert_node_tail (10)
	root = root.insert_node_tail (15)
	root = root.insert_node_tail (20)
	root.display_list ()
	root = root.reverse()
	root.display_list ()

	fmt.Println ("Reverse display 1 ......")
	root.reverse_display()

	var root1 *List = nil
	root1 = root1.insert_node_head (100)
	root1 = root1.insert_node_head (200)
	root1 = root1.insert_node_head (300)
	root1 = root1.insert_node_head (400)

	root1.display_list ()

	fmt.Println ("Reverse display 2 ......")
	root1.reverse_display()

	root1.delete_node(200)
	root1.display_list ()


	root1.delete_node(900)
	root1.display_list ()

	fmt.Println ("Insert sorted ....")
	var root2 *List = nil
	root2 = root2.insert_sorted (10)
	root2 = root2.insert_sorted (1)
	root2 = root2.insert_sorted (99)
	root2 = root2.insert_sorted (25)
	root2 = root2.insert_sorted (7)

	root2.display_list ()

    
}