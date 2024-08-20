class Solution {
public:
    /**
     * Função para mesclar k listas encadeadas ordenadas em uma única lista encadeada ordenada.
     * @param lists: Um vetor de ponteiros para as cabeças das listas encadeadas que precisam ser mescladas.
     * @return: Ponteiro para a cabeça da lista encadeada mesclada.
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Função lambda (uma função anônima) que define como comparar dois nós na fila de prioridade.
        // Essa função retorna true se o valor do nó 'a' for maior que o valor do nó 'b'.
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // Fila de prioridade (min-heap) que armazena nós da lista encadeada.
        // Ela sempre manterá o nó com o menor valor no topo, usando a função de comparação definida acima.
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        // Adiciona o primeiro nó de cada lista encadeada na fila de prioridade, se a lista não estiver vazia.
        for (ListNode* list : lists) {
            if (list != nullptr) { // Verifica se a lista não está vazia
                pq.push(list); // Adiciona o nó à fila de prioridade
            }
        }

        // Cria um nó dummy (fictício) para iniciar a lista encadeada resultante.
        // Isso facilita a construção da lista resultante.
        ListNode* result = new ListNode(-1);
        ListNode* temp1 = result; // Ponteiro auxiliar que nos ajudará a construir a lista resultante

        // Continua processando até que a fila de prioridade esteja vazia
        while (!pq.empty()) {
            // Pega o nó com o menor valor do topo da fila de prioridade
            ListNode* temp = pq.top();
            pq.pop(); // Remove o nó da fila de prioridade

            // Adiciona este nó ao final da lista resultante
            temp1->next = temp;
            temp1 = temp1->next; // Move o ponteiro auxiliar para o próximo nó na lista resultante

            // Se o nó atual tiver um próximo nó, adiciona o próximo nó à fila de prioridade
            if (temp->next != nullptr) {
                pq.push(temp->next); // Insere o próximo nó na fila
            }
        }

        // Retorna o próximo nó após o nó dummy, que é a cabeça da lista encadeada mesclada
        return result->next;
    }
};
