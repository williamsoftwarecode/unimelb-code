int isperfect(int i);

int 
nextperfect(int n) { 
	int i = n+1; 
	
	while (isperfect(i)==0) {
		i++;
	} 
	return i;	
}

