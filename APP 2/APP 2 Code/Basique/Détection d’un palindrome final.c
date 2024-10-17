int EstPalindrome(char chaineDeCaracteres[], int taille)
{
	char palindrome [size + 1];
	int j = size - 1;
	for (int i = 0; i < taille; i++)
	{
		palindrome[j] = word[i];
		j--;
	}
	palindrome[size] = '\0';
	for (int i = 0; i < taille; i++)
	{
		if(palindrome[i] != word[i])
			return 0;
	}
	return 1;
}
