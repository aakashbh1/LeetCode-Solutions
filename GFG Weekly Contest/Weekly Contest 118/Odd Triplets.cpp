long long countTriplet(int N, vector<int> A, int X)
    {
       int count = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) continue; // Skip even numbers
        
        for (int j = i + 1; j < N; j++) {
            if (A[j] % 2 == 0) continue; // Skip even numbers
            
            if (j - i >= X) { // Check condition 1: X ≤ j - i
                for (int k = j + 1; k < N; k++) {
                    if (A[k] % 2 == 0) continue; // Skip even numbers
                    
                    if (k - j >= X) { // Check condition 2: X ≤ k - j
                        count++;
                    }
                }
            }
        }
    }
    
    return count;
    }
