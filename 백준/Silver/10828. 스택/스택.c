int main(){
	int N;
	int num[100000];
	int* cur = num;
	int size = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char oper[6] = "";
		int num;
		scanf("%s", oper);
		switch (oper[1]) {
			case 'u':
				scanf("%d", &num);
				*(cur + size++) = num;
				break;
			case 'i':
				printf("%d\n", size);
				break;
			case 'm':
				printf("%d\n", size ? 0 : 1);
				break;
			case 'o':
				if (oper[0] == 'p') {
					if (size == 0) {
						printf("-1\n");
					}
					else {
						printf("%d\n", *(cur + size-- - 1));
					}
				}
				else {
					printf("%d\n", size ? *(cur + size - 1) : -1);
				}
				break;
		}
	}
}