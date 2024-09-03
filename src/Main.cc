#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long encontrarMaior(long long arr[], int tamanho)
{
    long long max = arr[0];
    for (int i = 1; i < tamanho; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
// Insertion Sort
void insertionSort(long long array[], int tamanho)
{
    for (int i = 1; i < tamanho; ++i)
    {
        long long chave = array[i];
        long long j = i - 1;
        while (j >= 0 && array[j] > chave)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = chave;
    }
}

int encontrarMaximo(long long arr[], int tamanho)
{
    long long maximo = arr[0];
    for (int i = 1; i < tamanho; ++i)
    {
        if (arr[i] > maximo)
        {
            maximo = arr[i];
        }
    }
    return maximo;
}
// Função para preencher o array com números aleatórios
void preencherArray(long long array[], int tamanho, int tamanhoNumerosBytes)
{
    srand(time(nullptr));
    long long maxNumero = (1LL << (8 * tamanhoNumerosBytes)) - 1; // Maior número possível com o tamanho especificado
    for (int i = 0; i < tamanho; ++i)
    {
        array[i] = rand() % (maxNumero + 1); // Números aleatórios de 0 a maxNumero
    }
}

// Função para imprimir o array
void imprimirArray(long long array[], int tamanho)
{
    for (int i = 0; i < tamanho; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Função para trocar dois elementos de posição no array
void trocar(long long &a, long long &b)
{
    long long temp = a;
    a = b;
    b = temp;
}

// Bubble Sort
void bubbleSort(long long array[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; ++i)
    {
        for (int j = 0; j < tamanho - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                trocar(array[j], array[j + 1]);
            }
        }
    }
}

// merge
void merge(long long arr[], int l, int m, int r)
{
    long long n1 = m - l + 1;
    long long n2 = r - m;

    // Cria arrays temporários
    long long *L = new long long[n1];
    long long *R = new long long[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Faz a intercalação dos arrays temporários de volta para arr[l..r]
    long long i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Libera a memória alocada
    delete[] L;
    delete[] R;
}
void contagemDigitos(long long arr[], int tamanho, int lugar, int maxNumero)
{
    const int base = 10; // Base decimal

    long long *saida = new long long[tamanho]; // Alocar dinamicamente memória para o array de saída
    long long contagem[base] = {0}; // Array de contagem para os dígitos

    // Contagem da ocorrência de cada dígito em 'lugar'
    for (int i = 0; i < tamanho; ++i)
    {
        contagem[(arr[i] / lugar) % base]++;
    }

    // Atualização do array de contagem para conter a posição correta de cada dígito na saída
    for (int i = 1; i < base; ++i)
    {
        contagem[i] += contagem[i - 1];
    }

    // Construção do array de saída
    for (int i = tamanho - 1; i >= 0; --i)
    {
        saida[contagem[(arr[i] / lugar) % base] - 1] = arr[i];
        contagem[(arr[i] / lugar) % base]--;
    }

    // Copia o array de saída de volta para o array original
    for (int i = 0; i < tamanho; ++i)
    {
        arr[i] = saida[i];
    }    delete[] saida; // Liberar a memória alocada para o array de saída

}


void radixSort(long long arr[], int tamanho)
{
    long long maximo = encontrarMaximo(arr, tamanho); // Encontra o máximo elemento no array

    // Realiza o Radix Sort para cada lugar (posição) do número
    for (int lugar = 1; maximo / lugar > 0; lugar *= 10)
    {
        contagemDigitos(arr, tamanho, lugar, maximo);
    }
}

void bucketSort(long long arr[], int tamanho) {
    int numBaldes = 100; // Número de baldes

    // Encontrar o máximo elemento no array
    long long maximo = encontrarMaximo(arr, tamanho);

    // Determinar o intervalo de valores em cada balde
    long long intervalo = (maximo + 1) / numBaldes;

    // Criar baldes
    long long baldes[numBaldes][tamanho];

    // Inicializar os tamanhos dos baldes como 0cd. 
    long long tamanhos[numBaldes] = {0};

    // Distribuir os elementos nos baldes
    for (int i = 0; i < tamanho; ++i) {
        long long indice = arr[i] / intervalo;
        baldes[indice][tamanhos[indice]++] = arr[i];
    }

    // Ordenar cada balde e mesclar os elementos de volta para o array original
    long long index = 0;
    for (int i = 0; i < numBaldes; ++i) {
        insertionSort(baldes[i], tamanhos[i]); // Usar insertionSort para ordenar cada balde
        for (int j = 0; j < tamanhos[i]; ++j) {
            arr[index++] = baldes[i][j];
        }
    }
}

// Função principal que implementa o Merge Sort
void mergeSort(long long arr[], int l, int r)
{
    if (l >= r)
        return;
    long long m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// shell sort
void shellSort(long long arr[], int tamanho)
{
    // Começa com um grande intervalo, depois reduz o intervalo
    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2)
    {
        // Realiza a ordenação dos elementos em intervalos
        for (int i = intervalo; i < tamanho; i += 1)
        {
            // Pega o elemento em intervalo para inserção posteriormente
            int chave = arr[i];

            // Move os elementos do subarray[0..i-intervalo], que são
            // maiores que a chave, para uma posição à frente de sua posição atual
            int j;
            for (j = i; j >= intervalo && arr[j - intervalo] > chave; j -= intervalo)
            {
                arr[j] = arr[j - intervalo];
            }

            // Insere a chave na posição correta
            arr[j] = chave;
        }
    }
}






// Função para ordenar o array usando o algoritmo Counting Sort
void countingSort(long long arr[], int tamanho)
{
    // Encontra o maior elemento no array
    long long max = encontrarMaior(arr, tamanho) + 1;

    // Cria um array de contagem e inicializa todos os elementos como 0
    long long count[max] = {0};

    // Conta a frequência de cada elemento
    for (int i = 0; i < tamanho; ++i)
    {
        count[arr[i]]++;
    }

    // Atualiza o array de contagem para ter as posições corretas dos elementos no array ordenado
    for (int i = 1; i < max; ++i)
    {
        count[i] += count[i - 1];
    }

    // Cria um array temporário para armazenar os elementos ordenados
    long long output[tamanho];

    // Preenche o array de saída com os elementos ordenados com base no array de contagem
    for (int i = tamanho - 1; i >= 0; --i)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copia os elementos ordenados de volta para o array original
    for (int i = 0; i < tamanho; ++i)
    {
        arr[i] = output[i];
    }
}

void selectionSort(long long arr[], int n)
{
    long long i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Função para intercalar dois subarrays de arr[]
// Primeiro subarray é arr[l..m]
// Segundo subarray é arr[m+1..r]
void quick(long long arr[], int l, int m, int r)
{
    long long n1 = m - l + 1;
    long long n2 = r - m;

    // Cria arrays temporários
    long long L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Faz a intercalação dos arrays temporários de volta para arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que implementa o Merge Sort
void QuickSort(long long arr[], int l, int r)
{
    if (l >= r)
        return;
    long long m = l + (r - l) / 2;
    QuickSort(arr, l, m);
    QuickSort(arr, m + 1, r);
    quick(arr, l, m, r);
}

// Função para medir o tempo de execução
double medirTempoExecucao(void (*funcaoOrdenacao)(long long[], int), long long array[], int tamanho)
{
    clock_t inicio, fim;
    inicio = clock();
    funcaoOrdenacao(array, tamanho);
    fim = clock();
    return double(fim - inicio) / CLOCKS_PER_SEC;
}

double medir_tempo_quick(void (*funcaoOrdenacao)(long long[], int, int), long long array[], int l, int r)
{
    clock_t inicio, fim;
    inicio = clock();
    funcaoOrdenacao(array, l, r);
    fim = clock();
    return double(fim - inicio) / CLOCKS_PER_SEC;
}

void clonar_array(long long array[], long long array_copia[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        array_copia[i] = array[i];
    }
}

int main()
{
    int tamanho; 
    cin >> tamanho;
    int tamanhoNumerosBytes = 20;


    long long array[tamanho];

    preencherArray(array, tamanho, tamanhoNumerosBytes);
    long long array_copia[tamanho];
 
    clonar_array(array, array_copia, tamanho);

    // Bubble Sort
    float tempoBubbleSort = medirTempoExecucao(bubbleSort, array, tamanho);
    cout << "\nTempo de execucao do Bubble Sort: " << tempoBubbleSort << " segundos\n";
    clonar_array(array_copia, array, tamanho);

    // Insertion Sort
    float tempoInsertionSort = medirTempoExecucao(insertionSort, array, tamanho);
    cout << "\nTempo de execucao do Insertion Sort: " << tempoInsertionSort << " segundos\n";
    clonar_array(array_copia, array, tamanho);

    float tempoSelectionSort = medirTempoExecucao(selectionSort, array, tamanho);
    cout << "\nTempo de execucao do Selection Sort: " << tempoSelectionSort << " segundos\n";
    clonar_array(array_copia, array, tamanho);

    float tempoQuickSort = medir_tempo_quick(QuickSort, array, 0, tamanho - 1);
    cout << "\n Tempo de execucao do Quick Sort: " << tempoQuickSort << " segundos\n";
    clonar_array(array_copia, array, tamanho);

    float tempoMergeSort = medir_tempo_quick(mergeSort, array, 0, tamanho - 1);
    cout << "\n Tempo de execucao do Merge Sort: " << tempoMergeSort << " segundos\n";
    clonar_array(array_copia, array, tamanho);

    float tempoShellSort = medirTempoExecucao(shellSort, array, tamanho);
    cout << "\n Tempo de execucao do Shell Sort: " << tempoShellSort << " segundos\n";
    clonar_array(array_copia, array, tamanho);

    float tempoCountingSort = medirTempoExecucao(countingSort, array, tamanho);
    cout << "\n Tempo de execucao do Counting Sort: " << tempoCountingSort << " segundos\n";
    clonar_array(array_copia, array, tamanho);

    float tempoBucketSort = medirTempoExecucao(bucketSort, array, tamanho);
    cout << "\n Tempo de execucao do Bucket Sort: " << tempoBucketSort << " segundos\n";
    clonar_array(array_copia, array, tamanho);

    float tempoRadixSort = medirTempoExecucao(radixSort, array, tamanho);
    cout << "\n Tempo de execucao do Radix Sort: " << tempoRadixSort << "segundos\n" << endl;
    clonar_array(array_copia, array, tamanho);

    return 0;
}
