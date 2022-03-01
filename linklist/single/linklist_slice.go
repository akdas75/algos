package main


import (

	"fmt"
	"sort"
)

func indexOf (ll []int , element int)  (int) {
	for k, v := range ll {
		if element == v {
			return k
		}
	}
	return -1    //not found.
 }


func main () {

	fmt.Println ("Linklist using slice")



	ll := make ([]int, 0, 5)

	/* Inserting */
    ll = append (ll, 10) 
	ll = append (ll, 20) 
	ll = append (ll, 30) 
	ll = append (ll, 40) 

	fmt.Println (ll)

	/* Reversing */
	for i, j := 0, len(ll)-1; i < j; i, j = i+1, j-1 {
		ll[i], ll[j] = ll[j], ll[i]
	}

	fmt.Println (ll)

    /* sorting */
	sort.Slice(ll, func(i, j int) bool {
		return ll[j] > ll[i]
	 })

	 fmt.Println (ll)

	/* Deleting */
	idx := indexOf (ll, 30)
	fmt.Println (idx)

	ll = append (ll [:2] , ll [3:]...) 
	//fmt.Println (mm)
	fmt.Println (ll)


}