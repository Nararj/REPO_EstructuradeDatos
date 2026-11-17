/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Dividimos la lista
    ListNode* dividirLista(ListNode* head) {
        // Comienza en el primer nodo, avanza un nodo
        ListNode* lento = head;
        // Comienza en el segundo nodo, avanza dos nodos
        ListNode* rapido = head->next;

        // Si el puntero ni su siguiente nodo esta vacio 
        while (rapido != nullptr && rapido->next != nullptr) {
            // Avanzamos lento un nodo y rapido dos nodos
            lento = lento->next;
            rapido = rapido->next->next;
        }

        // lento queda en el final de la primera mitad
        ListNode* segundaMitad = lento->next;
        // cortamos la lista en dos
        lento->next = nullptr;
        return segundaMitad;
    }

    // Apuntamos al incio de las listas y usamos un nodo auxiliar para ir armando la lista ordenada
    ListNode* mezclar(ListNode* l1, ListNode* l2) {
        ListNode nodoFalso(0);
        ListNode* cola = &nodoFalso;

        // Mientras ninguna de las listas este vacia, vamos comparando los nodos y agregando el menor a la lista ordenada
        while (l1 != nullptr && l2 != nullptr) {
            // Si el valor del nodo de la primera lista es menor o igual al valor del nodo de la segunda lista, agregamos 
            // el nodo de la primera lista a la lista ordenada y avanzamos al siguiente nodo de la primera lista. De lo contrario, 
            // agregamos el nodo de la segunda lista a la lista ordenada y avanzamos al siguiente nodo de la segunda lista.
            if (l1->val <= l2->val) {
                cola->next = l1;
                l1 = l1->next;
            } else {
                cola->next = l2;
                l2 = l2->next;
            }
            cola = cola->next;
        }

        // Si quedan elementos en una de las listas, los agregamos al final
        if (l1 != nullptr) {
            cola->next = l1;
        } else {
            cola->next = l2;
        }

        // Devolvemos el siguiente del nodo auxiliar, que es el inicio de la lista ordenada
        return nodoFalso.next;
    }

    // Recibir una lista y devolverla ordenada
    ListNode* mergeSort(ListNode* head) {
        // Si una lista esta vacia o solo tiene un elemnto devolvemos la lista
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Dividimos la lista en dos mitades, ordenamos cada mitad y luego las mezclamos
        ListNode* segundaMitad = dividirLista(head);
        // Se ordena cada mitad llamando a si misma en una lista mas pequeña
        ListNode* izquierda = mergeSort(head);
        ListNode* derecha = mergeSort(segundaMitad);

        // Mezclamos las dos mitades
        return mezclar(izquierda, derecha);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};