#include <vector>

class Solution {
private:
    int count;  // Contador para os pares inversos

public:
    Solution() : count(0) {}  // Inicializa o contador

    int reversePairs(std::vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);  // Inicia a ordenação e contagem
        return count;  // Retorna o total de pares inversos
    }

private:
    std::vector<int> mergeSort(std::vector<int>& nums, int start, int end) {
        if (start == end) {
            return std::vector<int>{nums[start]};  // Retorna o único elemento se os índices forem iguais
        }
        
        int mid = start + (end - start) / 2;  // Calcula o ponto médio
        std::vector<int> leftHalf = mergeSort(nums, start, mid);  // Ordena a primeira metade
        std::vector<int> rightHalf = mergeSort(nums, mid + 1, end);  // Ordena a segunda metade
        
        // Contagem dos pares inversos
        int index1 = 0, index2 = 0;
        for (; index1 < leftHalf.size(); ++index1) {
            while (index2 < rightHalf.size() && 2LL * rightHalf[index2] < leftHalf[index1]) {
                ++index2;  // Incrementa o índice enquanto o elemento da direita for menor
            }
            count += index2;  // Adiciona ao contador o número de pares inversos encontrados
        }
        
        // Mesclar as duas metades ordenadas
        std::vector<int> mergedArray(end - start + 1);  // Vetor para armazenar a metade mesclada
        int index = 0;
        index1 = 0, index2 = 0;
        while (index1 < leftHalf.size() || index2 < rightHalf.size()) {
            if (index1 < leftHalf.size() && index2 < rightHalf.size()) {
                mergedArray[index++] = leftHalf[index1] <= rightHalf[index2] ? leftHalf[index1++] : rightHalf[index2++];  // Mescla os elementos em ordem
            } else if (index1 < leftHalf.size()) {
                mergedArray[index++] = leftHalf[index1++];  // Adiciona o restante dos elementos da esquerda
            } else {
                mergedArray[index++] = rightHalf[index2++];  // Adiciona o restante dos elementos da direita
            }
        }
        return mergedArray;  // Retorna o vetor mesclado
    }
};
