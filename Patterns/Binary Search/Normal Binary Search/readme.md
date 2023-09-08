This is a template type of binary search which is used in sorted arrays toh find something in short time of logn.
Template:
  
     while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == target)
                return true;
            else if (arr[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
  
