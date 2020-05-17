#code exe 0.96 tc=nlogn
def merge(arr,left,mid,right):
    i = left
    j = mid+1
    k = left
    temp = []
    c=0
    while i<=mid and j<=right :
        if arr[i]<=arr[j]:
            temp.append(arr[i])
            i+=1
        else:
            temp.append(arr[j])
            j += 1
            c += (mid-i+1)
    while i<=mid:
        temp.append(arr[i])
        i+=1
    while j<=right:
        temp.append(arr[j])
        j+=1
    for loop in range(left,right+1):
        arr[loop] = temp[loop-left]
    return c

def mergeSort(arr, left, right):
    inv_count = 0
    if left<right :
        mid = (right + left)//2
        inv_count += mergeSort(arr,left,mid)
        inv_count += mergeSort(arr,mid+1,right)
        inv_count += merge(arr,left,mid,right)
    
    return inv_count
for _ in range(int(input())):
    n = int(input())
    arr = input().split()
    for i in range(n):
        arr[i] = int(arr[i])
    
    print(mergeSort(arr,0,n-1))
