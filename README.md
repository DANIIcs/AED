# Esquema General para Resolver Problemas Utilizando Tablas Hash en C++

Los códigos proporcionados abordan problemas que se resuelven eficientemente utilizando **tablas hash** (o **`unordered_map`** en C++). Estos problemas comparten características comunes:

- **Necesidad de acceder o almacenar datos de forma rápida**.
- **Búsqueda, conteo o asociación de elementos basados en claves**.
- **Optimización del tiempo de ejecución**, generalmente reduciendo la complejidad de O(n²) a O(n).

A continuación, se presenta un esquema general para abordar y resolver problemas similares utilizando tablas hash, junto con explicaciones detalladas y consideraciones clave.

## **1. Comprender el Problema y Detectar el Uso de Tablas Hash**

Antes de comenzar a codificar, es crucial entender completamente el enunciado del problema y determinar si una tabla hash es adecuada:

- **Patrones Comunes**:
  - **Conteo de frecuencias**: Necesitas contar cuántas veces aparece un elemento.
  - **Asociaciones únicas**: Necesitas mapear elementos de un conjunto a otro.
  - **Detección de duplicados**: Necesitas saber si un elemento ya ha aparecido.
  - **Acceso rápido a elementos**: Necesitas acceder a elementos en tiempo constante.

- **Ejemplos**:
  - **Análisis de cadenas**: Verificar si dos cadenas son isomorfas.
  - **Secuencias repetidas**: Encontrar subsecuencias repetidas en una cadena de ADN.
  - **Cálculo de distancias**: Contar el número de "boomerangs" en un conjunto de puntos.

## **2. Identificar las Estructuras de Datos Necesarias**

Una vez que has determinado que una tabla hash es adecuada, identifica qué información necesitas almacenar:

- **Claves y Valores**:
  - **Clave**: El elemento por el cual vas a indexar (por ejemplo, un carácter, una cadena, una distancia).
  - **Valor**: La información asociada a la clave (por ejemplo, una frecuencia, una asociación, un contador).

- **Tipos de Tablas Hash en C++**:
  - **`unordered_map`**: Mapea claves únicas a valores.
  - **`unordered_set`**: Almacena claves únicas, útil para verificar existencia.
  - **`map`** y **`set`**: Versiones ordenadas, si se requiere orden.

## **3. Diseñar el Algoritmo Paso a Paso**

### **Paso 1: Inicialización**

- **Declarar la tabla hash** con el tipo de clave y valor adecuados.

  ```cpp
  unordered_map<char, int> charCount;
  unordered_map<string, int> sequenceCount;
  unordered_map<int, int> distanceCount;
  ```

### **Paso 2: Iteración sobre los Datos**

- **Recorrer la estructura de datos** principal (cadena, vector, etc.).

  ```cpp
  for (char c : s) { /* ... */ }
  for (int i = 0; i < s.length() - 9; i++) { /* ... */ }
  for (int i = 0; i < points.size(); i++) { /* ... */ }
  ```

### **Paso 3: Actualizar la Tabla Hash**

- **Insertar o actualizar valores** en la tabla hash según la lógica del problema.

  - **Conteo de frecuencias**:

    ```cpp
    charCount[c]++;
    ```

  - **Asociación única**:

    ```cpp
    if (mapping.find(c) == mapping.end()) {
        mapping[c] = t[i];
    }
    ```

  - **Conteo basado en cálculos**:

    ```cpp
    int dist = calcularDistancia(points[i], points[j]);
    distanceCount[dist]++;
    ```

### **Paso 4: Procesamiento Adicional (si es necesario)**

- **Evaluar condiciones** o **acumular resultados** basados en la información de la tabla hash.

  - **Detección de duplicados**:

    ```cpp
    if (charCount[c] > 1) {
        // Encontrado duplicado
    }
    ```

  - **Cálculo de combinaciones**:

    ```cpp
    total += count * (count - 1);
    ```

### **Paso 5: Devolver o Mostrar el Resultado**

- **Retornar el resultado** en el formato requerido por el problema.

  ```cpp
  return total;
  return resultVector;
  ```

## **4. Consideraciones de Implementación**

### **a. Manejo de Colisiones**

- En **`unordered_map`** y **`unordered_set`**, las colisiones se manejan internamente, pero es bueno entender que pueden afectar el rendimiento en casos extremos.

### **b. Funciones Hash Personalizadas**

- Para tipos de datos personalizados, podrías necesitar proporcionar una función hash personalizada.

  ```cpp
  struct MyType { /* ... */ };
  namespace std {
      template <>
      struct hash<MyType> {
          size_t operator()(const MyType& obj) const {
              // Implementación de la función hash
          }
      };
  }
  ```

### **c. Complejidad Temporal**

- **Inserción y Búsqueda** en **`unordered_map`** son O(1) en promedio, pero O(n) en el peor caso.
- **Asegúrate de que las operaciones dentro de los bucles** sean eficientes para mantener el rendimiento general.

## **5. Ejemplo de Aplicación del Esquema General**

Tomemos uno de los códigos como ejemplo: **Encontrar Secuencias Repetidas de ADN**

### **Paso 1: Comprender el Problema**

- Necesitamos encontrar todas las secuencias de 10 caracteres que aparecen más de una vez en una cadena.

### **Paso 2: Identificar Estructuras de Datos**

- Usaremos un **`unordered_map<string, int>`** para contar las frecuencias de las secuencias.

### **Paso 3: Diseñar el Algoritmo**

- **Iterar** sobre la cadena y extraer todas las subsecuencias de longitud 10.
- **Actualizar** el conteo en el mapa.
- **Recorrer** el mapa y seleccionar las secuencias con conteo > 1.

### **Paso 4: Implementación**

```cpp
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if(s.size() < 10) return ans;

    unordered_map<string, int> mp;
    for(int i = 0; i <= s.size() - 10; i++) {
        string str = s.substr(i, 10);
        mp[str]++;
    }

    for(auto it : mp) {
        if(it.second > 1) {
            ans.push_back(it.first);
        }
    }
    return ans;
}
```

## **6. Pasos para Resolver Nuevos Problemas**

Cuando te enfrentes a un nuevo problema, sigue estos pasos:

1. **Lee atentamente el enunciado** y entiende lo que se pide.
2. **Identifica si una tabla hash es adecuada** para optimizar la solución.
3. **Determina qué información necesitas almacenar** en la tabla hash.
4. **Elige las estructuras de datos apropiadas** (e.g., `unordered_map`, `unordered_set`).
5. **Diseña el algoritmo** siguiendo el esquema general:
   - Inicializa las estructuras de datos.
   - Itera sobre los datos de entrada.
   - Actualiza la tabla hash según la lógica.
   - Realiza procesamiento adicional si es necesario.
   - Devuelve el resultado.
6. **Considera casos bordes** y **prueba tu solución** con diferentes entradas.
7. **Analiza la complejidad temporal y espacial** de tu solución.

## **7. Consejos Adicionales**

- **Manejo de Colisiones y Unicidad**:
  - Si necesitas asegurar que no haya asignaciones duplicadas (como en el problema de cadenas isomorfas), verifica que los valores no estén ya mapeados a otras claves.

- **Optimización de Espacio**:
  - Si el espacio es una preocupación, considera alternativas como usar arrays si las claves son números pequeños o caracteres.

- **Funciones Hash Eficientes**:
  - Para tipos de datos complejos, asegúrate de que la función hash distribuya uniformemente las claves para evitar colisiones.

- **Pruebas Extensivas**:
  - Siempre prueba tu código con casos extremos y grandes conjuntos de datos para asegurarte de que funciona eficientemente.

## **8. Aplicación en Diferentes Tipos de Problemas**

- **Problemas de Anagramas**:
  - Usar tablas hash para contar frecuencias de caracteres.

- **Sumas Objetivo**:
  - Utilizar un `unordered_map` para almacenar complementos y verificar si existen.

- **Agrupación**:
  - Mapear claves a grupos (por ejemplo, agrupar palabras por su firma de ordenación).

- **Detección de Ciclos**:
  - Usar un `unordered_set` para detectar si un elemento ya ha sido visitado.

## **Conclusión**

Las tablas hash son herramientas poderosas para resolver una amplia variedad de problemas en programación competitiva y desarrollo de software. Al seguir este esquema general y comprender las necesidades específicas de cada problema, podrás diseñar soluciones eficientes y efectivas.

**Recuerda**: La clave está en entender profundamente el problema, elegir las estructuras de datos adecuadas y diseñar un algoritmo que aproveche las ventajas de las tablas hash.
