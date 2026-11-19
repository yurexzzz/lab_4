Задание 1. Добавление элемента в конец списка с указателем bottom

Для ускорения добавления элемента в конец однонаправленного списка используется дополнительный указатель bottom, который указывает на последнюю ячейку

- Добавление элемента в конец списка

AddAtEndWithBottom(Cell: top, Cell: bottom, Cell: new_cell)

    // Если список пустой
    If (top == null) Then

        top = new_cell
        bottom = new_cell
        new_cell.Next = null

    Else

        // Добавляем новую ячейку после последней
        bottom.Next = new_cell
        new_cell.Next = null

        // Обновляем указатель на последнюю ячейку
        bottom = new_cell

    End If

End AddAtEndWithBottom

Время работы O(1).

- Удаление элемента из списка

DeleteCell(Cell: top, Cell: bottom, Value: target)

    // Если список пустой
    If (top == null) Then
        Return
    End If

    // Если удаляем первую ячейку
    If (top.Value == target) Then

        Cell: target_cell = top
        top = top.Next

        // Если список стал пустым
        If (top == null) Then
            bottom = null
        End If

        free(target_cell)
        Return

    End If

    // Ищем ячейку для удаления
    Cell: previous = top
    Cell: current = top.Next

    While (current != null) And (current.Value != target)

        previous = current
        current = current.Next

    End While

    // Если элемент не найден
    If (current == null) Then
        Return
    End If

    // Удаляем найденную ячейку
    previous.Next = current.Next

    // Если удаляем последнюю ячейку
    If (current == bottom) Then
        bottom = previous
    End If

    free(current)

End DeleteCell

Время работы O(N), поскольку необходимо найти удаляемую ячейку

Влияние дополнительного указателя bottom на другие алгоритмы:
- При добавлении элемента в начало необходимо обновлять bottom, если список пустой
- При удалении первого элемента необходимо проверить, не стал ли список пустым
- При удалении последнего элемента нужно найти предпоследнюю ячейку и переместить bottom на неё
- При удалении единственного элемента необходимо обнулить оба указателя
- При поиске элемента дополнительных изменений не требуется

Добавление в конец ускоряется с O(N) до O(1), но удаление последнего элемента по-прежнему занимает O(N)

Задание 2. Поиск наибольшего элемента в неотсортированном однонаправленном списке

Для нахождения максимального элемента необходимо последовательно проверить все ячейки списка

FindMax(Cell: top)

    // Если список пустой
    If (top == null) Then
        Return null
    End If

    // Начальное максимальное значение
    max = top.Value
    Cell: current = top.Next

    // Просматриваем остальные ячейки
    While (current != null)

        If (current.Value > max) Then
            max = current.Value
        End If

        current = current.Next

    End While

    Return max

End FindMax

Время работы O(N), так как необходимо проверить каждую ячейку списка.

Дополнительная память O(1)

Задание 3. Добавление элемента в начало двунаправленного списка

В двунаправленном списке каждая ячейка содержит два указателя: Next и Prev

AddAtBeginning(Cell: top, Cell: bottom, Cell: new_cell)

    // Новая ячейка становится первой
    new_cell.Prev = null
    new_cell.Next = top

    // Если список не пустой
    If (top != null) Then

        top.Prev = new_cell

    Else

        // Если список пустой, новая ячейка также последняя
        bottom = new_cell

    End If

    // Обновляем начало списка
    top = new_cell

End AddAtBeginning

Время работы O(1)

Задание 4. Добавление элемента в конец двунаправленного списка

AddAtEnd(Cell: top, Cell: bottom, Cell: new_cell)

    // Новая ячейка становится последней
    new_cell.Next = null
    new_cell.Prev = bottom

    // Если список не пустой
    If (bottom != null) Then

        bottom.Next = new_cell

    Else

        // Если список пустой, новая ячейка также первая
        top = new_cell

    End If

    // Обновляем конец списка
    bottom = new_cell

End AddAtEnd

Время работы O(1)

Задание 5. Использование алгоритма InsertCell для добавления элементов

Вместо непосредственного изменения ссылок в алгоритмах добавления в начало и конец используем общий алгоритм InsertCell

Вставка новой ячейки после заданной

Для удобства используем следующий вариант: если after_me равен null, новая ячейка вставляется в начало списка

InsertCell(Cell: top, Cell: bottom, Cell: after_me, Cell: new_cell)

    // Вставка в начало списка
    If (after_me == null) Then

        new_cell.Prev = null
        new_cell.Next = top

        If (top != null) Then
            top.Prev = new_cell
        Else
            bottom = new_cell
        End If

        top = new_cell

    Else

        // Вставка после заданной ячейки
        new_cell.Next = after_me.Next
        new_cell.Prev = after_me

        If (after_me.Next != null) Then
            after_me.Next.Prev = new_cell
        Else
            bottom = new_cell
        End If

        after_me.Next = new_cell

    End If

End InsertCell

- Добавление в начало через InsertCell

AddAtBeginning(Cell: top, Cell: bottom, Cell: new_cell)

    InsertCell(top, bottom, null, new_cell)

End AddAtBeginning

Добавление в конец через InsertCell

AddAtEnd(Cell: top, Cell: bottom, Cell: new_cell)

    InsertCell(top, bottom, bottom, new_cell)

End AddAtEnd

Время работы O(1) для каждой операции

Задание 6. Удаление определённой ячейки из двунаправленного списка

Поскольку каждая ячейка содержит указатели на предыдущую и следующую ячейки, можно удалить заданную ячейку, не проходя весь список

DeleteCell(Cell: top, Cell: bottom, Cell: target_cell)

    // Проверяем существование ячейки
    If (target_cell == null) Then
        Return
    End If

    // Обновляем ссылку предыдущей ячейки
    If (target_cell.Prev != null) Then

        target_cell.Prev.Next = target_cell.Next

    Else

        // Удаляется первая ячейка
        top = target_cell.Next

    End If

    // Обновляем ссылку следующей ячейки
    If (target_cell.Next != null) Then

        target_cell.Next.Prev = target_cell.Prev

    Else

        // Удаляется последняя ячейка
        bottom = target_cell.Prev

    End If

    // Освобождаем память
    free(target_cell)

End DeleteCell

Время работы O(1), поскольку адрес удаляемой ячейки уже известен

Задание 7. Поиск в отсортированном двунаправленном списке с нижнего ограничителя

В отсортированном двунаправленном списке можно выполнять поиск как от верхнего, так и от нижнего ограничителя

При поиске с нижнего ограничителя движение осуществляется в обратном направлении через указатель Prev

FindCellFromBottom(Cell: bottom, Name: target)

    Cell: current = bottom.Prev

    // Ищем элемент, двигаясь от конца к началу
    While (current != null)

        If (current.Name == target) Then
            Return current
        End If

        If (current.Name < target) Then
            Return null
        End If

        current = current.Prev

    End While

    Return null

End FindCellFromBottom


Начинать поиск с нижнего ограничителя можно. Если искомый элемент находится ближе к концу списка, количество просмотренных ячеек может уменьшиться

Однако асимптотическая сложность поиска не изменится и останется O(N) в худшем случае

Задание 8. Вставка элемента в отсортированный двунаправленный список с ограничителями

В данном алгоритме используются два ограничителя:

- Верхний ограничитель содержит минимально возможное значение.

- Нижний ограничитель содержит максимально возможное значение.

Это позволяет упростить поиск позиции для вставки новой ячейки

InsertSorted(Cell: top, Cell: new_cell)

    // Начинаем поиск с верхнего ограничителя
    Cell: after_me = top

    // Находим место для новой ячейки
    While (after_me.Next.Value < new_cell.Value)

        after_me = after_me.Next

    End While

    // Вставляем новую ячейку между двумя ячейками
    new_cell.Next = after_me.Next
    new_cell.Prev = after_me

    after_me.Next.Prev = new_cell
    after_me.Next = new_cell

End InsertSorted

Время поиска позиции O(N)

Время непосредственной вставки O(1)

Общее время работы O(N)

Задание 9. Проверка отсортированности связного списка

Для проверки отсортированности необходимо последовательно сравнить значения соседних ячеек

Предполагается сортировка по возрастанию

IsSorted(Cell: top)

    // Пустой список считается отсортированным
    If (top == null) Then
        Return true
    End If

    Cell: current = top

    // Проверяем соседние ячейки
    While (current.Next != null)

        If (current.Value > current.Next.Value) Then
            Return false
        End If

        current = current.Next

    End While

    // Все элементы расположены по возрастанию
    Return true

End IsSorted

Время работы O(N), поскольку необходимо проверить все соседние пары ячеек

Дополнительная память O(1)