#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Paso 1: Construcción del grafo y cálculo de los grados de entrada.
        
        // `graph` es una lista de adyacencia donde cada curso tiene una lista de cursos dependientes.
        vector<vector<int>> graph(numCourses); 
        
        // `inDegree` almacena cuántos prerrequisitos tiene cada curso.
        vector<int> inDegree(numCourses, 0);

        // Rellenamos el grafo y los grados de entrada usando la lista de prerrequisitos.
        for (const vector<int>& prereq : prerequisites) {
            int course = prereq[0];       // El curso que tiene un prerrequisito
            int prereqCourse = prereq[1]; // El curso que es el prerrequisito
            graph[prereqCourse].push_back(course); // Agregamos `course` como dependiente de `prereqCourse`
            inDegree[course]++;           // Aumentamos el grado de entrada de `course`
        }

        // Paso 2: Inicializar la cola con todos los cursos que no tienen prerrequisitos.
        
        // Creamos una cola para almacenar los cursos que tienen `inDegree` igual a 0 (sin prerrequisitos).
        queue<int> q;
        
        // Recorremos cada curso y agregamos a la cola aquellos sin prerrequisitos.
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i); // Si `inDegree[i]` es 0, significa que este curso no necesita otros cursos antes.
            }
        }

        // Paso 3: Orden topológico utilizando BFS.
        
        // `order` almacenará el orden en el que podemos tomar los cursos.
        vector<int> order;
        
        // Procesamos cada curso en la cola (todos los cursos sin prerrequisitos al principio).
        while (!q.empty()) {
            int course = q.front(); // Tomamos el primer curso de la cola
            q.pop(); // Lo sacamos de la cola
            order.push_back(course); // Agregamos este curso al orden final porque puede tomarse ahora
            
            // Recorremos todos los cursos dependientes de `course`.
            for (int nextCourse : graph[course]) {
                inDegree[nextCourse]--; // Reducimos el número de prerrequisitos de `nextCourse`
                
                // Si `nextCourse` ahora no tiene prerrequisitos, lo agregamos a la cola.
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse); // Ahora puede ser tomado sin problemas, así que lo agregamos a la cola
                }
            }
        }

        // Paso 4: Verificación del resultado.
        
        // Si hemos agregado todos los cursos a `order`, entonces encontramos un orden válido.
        if (order.size() == numCourses) {
            return order; // Devolvemos el orden completo
        }
        
        // Si no hemos agregado todos los cursos, significa que hay un ciclo y no es posible completarlos.
        return {}; // Devolvemos un array vacío indicando que no se puede tomar todos los cursos
    }
};
