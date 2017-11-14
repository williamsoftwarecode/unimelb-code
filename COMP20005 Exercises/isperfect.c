int 
isperfect(int n) { 
	int i, sumfactors=0; 
	for (i=1; i<n; i++) {
		if (n%i==0) {
			sumfactors += i;
		}
	}
	if (n==sumfactors) {
		return 1; 
	} else {
		return 0; 
	}
}
