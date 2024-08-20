#include <vector>       // Inclui a biblioteca de vetores
#include <algorithm>    // Inclui a biblioteca para a função std::sort

class Solution {
public:
    /**
     * Função para encontrar a mediana de dois arrays ordenados.
     * @param nums1: Primeiro array ordenado.
     * @param nums2: Segundo array ordenado.
     * @return: A mediana dos dois arrays combinados.
     */
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Cria um vetor para armazenar todos os elementos dos dois arrays.
        // O vetor é do tipo double para garantir que a mediana seja calculada com precisão.
        std::vector<double> arr(nums1.size() + nums2.size());
        
        int j = 0;  // Variável para rastrear a posição no vetor combinado (arr)

        // Copia todos os elementos do primeiro array (nums1) para o vetor combinado (arr)
        for (int i : nums1) arr[j++] = i;

        // Copia todos os elementos do segundo array (nums2) para o vetor combinado (arr)
        for (int i : nums2) arr[j++] = i;

        // Ordena o vetor combinado em ordem crescente.
        std::sort(arr.begin(), arr.end());

        // Verifica se o número total de elementos no vetor combinado é par ou ímpar
        if (arr.size() % 2 == 0) {
            // Se for par, a mediana é a média dos dois elementos centrais do vetor
            return (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2;
        } else {
            // Se for ímpar, a mediana é simplesmente o elemento central do vetor
            return arr[arr.size() / 2];
        }
    }
};
