/**
 * Ex1.a)
 * Pseudo code of bubble sort:
 * for i=2 to n-1
 *  flag=false
 *  for j=1 to n-1-i
 *      if list[i]>list[i+1]
 *          temp = list[i]
 *          list[i]=list[i+1]
 *          list[i+1]=temp
 *          flag true
 *      endif
 *   endfor
 *   if flag= false
 *      break
 *   endif
 * endfor
 * 
 * Ex1.b)
 * Worst case: 
 * When the for loops go till the end,
 * which means the time complexity will be
 * n^2.
 * 
 * Best case:
 * When the list is already sorted,and the first
 * loop only loops once, which means the time complexity
 * is n.
 * 
 * Average case:
 * Average case is n^2
 * 
 * Ex1.c)
 * ->Heap sort is not stable because it does not preserve
 * the order of elements, because it...
 * 
 * ->Insertion sort, Merge sort, Bubblesort are stable because
 * they preserve the old position of the elements that don't need
 * to change. For example:
 * If we sort these strings based on the first letter
 * ab
 * bc
 * sg
 * be
 * In a stable algorithm we get:
 * ab
 * bc
 * be
 * sg
 * In an unstable, be might appear in the place of bc.
 * 
 * Ex1.d)
 * 
 * */
