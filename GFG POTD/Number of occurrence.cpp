// Number of occurrence
	int firstOccurence(int arr[], int n, int x){
	    int l=0;
	    int h=n-1;
	    int ans=-1;
	    while(l<=h){
	        int mid=l+(h-l)/2;
	        if(arr[mid]==x){
	            ans=mid;
	        h=mid-1;
	        }
	         else if(arr[mid]>x){
                 h=mid-1;
             }
	        else l=mid+1;
	        
	    }
	    return ans;
	}
	int lastOccurence(int arr[], int n, int x){
	    int l=0;
	    int h=n-1;
	    int ans=-1;
	    while(l<=h){
	        int mid=l+(h-l)/2;
	        if(arr[mid]==x){
	            ans=mid;
	            l=mid+1;
	            
	        }
	        else if(arr[mid]>x){
                 h=mid-1;
             }
	        else 
	        l=mid+1;
	    }
	    return ans;
	}
	int count(int arr[], int n, int x) {
	   
	   int first=firstOccurence(arr,n,x);
	   int last=lastOccurence(arr,n,x);
	   if(last==-1 && first==-1) return 0;
	   return last-first+1;
	    
	}
