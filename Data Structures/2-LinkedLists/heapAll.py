def parent(i):
    return (i-1)/2
def left(i):
    return 2*i+1
def right(i):
    return 2*i+2
def is_leaf(L,i):
    return 2*i+1>=len(L) and 2*i+2>=len(L)
def has_one_child(L,i):
    return 2*i+2>=len(L) and 2*i+1<len(L)

def swap(a,b):
    (a,b)=(b,a)
        
def heapify(L,i,par):
    if par=="up":
        up_heapify(L,i)
    elif par=="down":
        down_heapify(L,i)
    return L

def up_heapify(L,i):
    if i==0:
        return L
    if L[i]>=L[parent(i)]:
        swap(L[i],L[parent(i)])
        up_heapify(L,parent(i))

def down_heapify(L,i):
    if is_leaf(L,i):
        return
    if has_one_child(L,i):
        if L[i]<L[left(i)]:
            return
        else:
            swap(L[i],L[left(i)])
            down_heapify(L,left(i))
    else:
        if L[i]<L[left(i)] and L[i]<L[right(i)]:
            return
        elif L[left(i)]>L[right(i)]:
            swap(L[i],L[right(i)])
            down_heapify(L,right(i))
        else:
            swap(L[i],L[left(i)])
            down_heapify(L,left(i))


L=[10,10,10,8,8,8,7,6,5,4,3,2,1]
heap=[]
for v in L:
    heap.append(v)
    heap=heapify(heap,0,"down")

print heap    
