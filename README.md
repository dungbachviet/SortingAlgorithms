# 12 THUẬT TOÁN SẮP XẾP CƠ BẢN

Xin chào mọi người,  
Trong bài viết đầu tay này, mình xin trình bày về 12 giải thuật phổ biến và cơ bản trong lớp bài toán sắp xếp các chuỗi số, chuỗi ký tự. Ý tưởng của bài viết được khảo cứu và trích dẫn chủ yếu từ một số nguồn tài liệu hữu ích như : Geeksforgeeks.org, tutorialspoint.com, stackoverflow.com…  

Với mỗi giải thuật, tớ sẽ cố gắng trình bày và làm rõ chúng theo bố cục với những nội chính sau : 
+ Tư tưởng của giải thuật
+ Mã nguồn ( được minh họa trên một vài ngôn ngữ lập trình)
+ Độ phức tạp của thuật toán
+ Đưa ra nhận xét và đánh giá thuật toán.
+ So sánh với các giải thuật khác và Đưa ra giải pháp tối ưu cùng khả năng ứng của bài toán trong thực tế cuộc sống.

Mình rất mong chờ sẽ nhận được thật nhiều những ý kiến đóng góp từ mọi người để bài viết này ngày càng hoàn thiện hóa, cũng như trở thành một nguồn tài liệu có khả năng tham khảo cao và ngày một lan tỏa rộng rãi trong cộng đồng !  

Còn bây giờ, chúng ta sẽ bắt đầu với giải thuật cơ bản đầu tiên nhé ! 

**1.	Thuật toán Selection Sort (Sắp xếp chọn)**

1.1	Code minh họa 

```C++
// algorithm for Selection Sort
void selectionSort(double *unsortedArray, int size) {
	for (int index = 0; index < size - 1; index++) {
		int minIndex = index;
		for (int findMinIndex = index + 1; findMinIndex < size; findMinIndex++) {
			if (unsortedArray[findMinIndex] < unsortedArray[minIndex])
				minIndex = findMinIndex;
		}	
		swap(&unsortedArray[minIndex], &unsortedArray[index]);
	}
}

```

1.2	Ý tưởng giải thuật  

Với một mảng số ban đầu chưa được sắp xếp gồm size phần tử. Ý tưởng của thuật toán được mô tả thông qua các bước sau : 
+ Chọn 1 phần tử đầu tiên của dãy số, giả sử phần tử này là nhỏ nhất, lưu chỉ số phần tử này
+ Duyệt để so sánh phần tử nhỏ nhất này với các phần tử còn lại (tiếp theo) của dãy số. Nếu phát hiện có bất kỳ phần tử nào nhỏ hơn phần tử nhỏ nhất hiện tại, ta tiến hành thay đổi chỉ số của phần tử nhỏ nhất (do phần tử có giá trị nhỏ nhất đã khác)
+ Sau khi duyệt xong toàn bộ mảng, ta đã tìm ra được vị trí (chỉ số) của phần tử nhỏ nhất trong mảng đó. Lúc này, tiến hành hoán đổi vị trí của phần tử đầu tiên trong mảng với vị trí của phần tử nhỏ nhất trong mảng (đã thu được)
+ Sau khi hoán đổi, phần tử nhỏ nhất sẽ luôn nằm “cố định” ở đầu mảng, và phần tử này sẽ không còn đóng góp vai trò nào cho những lần sắp xếp tiếp theo. Có nghĩa rằng, ta giả sử mảng mới cần phải sắp xếp sẽ chỉ còn size – 1 phần tử (phía sau phần tử đầu tiên cố định). Rồi thực hiện lặp lại quá trình trên từ bước 1 tới bước cuối cùng …với ý định sau mỗi quá trình lặp lại đó, ta sẽ tìm kiếm và cố định được phần tử nhỏ nhất, phần tử nhỏ thứ 2, … phần tử nhỏ thứ size – 1. Và giải thuật kết thúc !  

1.3	Độ phức tạp của thuật toán :  

Thuật toán sử dụng 2 vòng for:
+  Vòng for thứ nhất chạy từ index =  0 tới size – 2. 
+ Vòng for thứ hai chạy từ index + 1 tới cuối mảng
Như vậy, đối với 1 dãy số gồm n phần tử , số lần duyệt qua từng phần tử trong mảng sẽ là : (n-1) + (n-2) + … + 1 . Vì vậy độ phức tạp của thuật toán trong tình huống tồi nhất sẽ là : O(n^2)  

1.4. Nhận xét thuật toán  

1.4.1. Ưu điểm  

- Selection Sort là một giải thuật đã hạn chế được khá nhiều số lần lặp so với giải thuật Sắp xếp Nổi bọt (do nó sử dụng biến chỉ số để lưu lại phần tử nhỏ nhất,… để đến cuối cùng mới tiến hành hoán vị)
- Giải thuật này có tính chất ổn định : Tức các phần tử các giá trị bằng nhau sẽ giữ nguyên vị trí tương đối của chúng như trước khi dãy số được sắp xếp
- Không đòi hỏi thêm không gian nhớ phụ, nên giải thuật mang tính chất “ Tại chỗ”
- Trong thực tế, giải thuật này có thể được sử dụng như một giải pháp hỗ trợ cho một giai đoạn nào đó trong những giải thuật sắp xếp khác

1.4.2. Nhược điểm :   

- Độ phức tạp của giải thuật tuy đã được cải thiện nhưng nhìn chung vẫn còn khá lớn so với các thuật toán sắp xếp hiệu quả
- Chưa giải quyết được vấn đề : đầu vào đã được sắp xếp

1.5. Giải pháp tối ưu :  

- Trong tình huống dãy số đầu vào đã được sắp xếp, giải pháp được đưa ra sẽ là : Sử dụng một biến hasSwapped để duyệt từ đầu tới cuối mảng, để phát hiện xem dãy số được sắp xếp tăng dần hay giảm dần chưa? Nếu hasSwapped = 0 khi duyệt theo chiều thuận tức dãy đã được sắp xếp tăng dần. Nếu hasSwapped = 0 khi duyệt theo chiều nghịch, tức dãy đã được sắp xếp giảm dần, vì thế sắp xếp lại tăng dần, ta chỉ việc đảo ngược dãy số đó!

2.Thuật toán Insertion Sort (Sắp xếp chèn)  

2.1. Mã nguồn minh họa :  

```C++
// algorithm for Insertion Sort
void insertionSort(double *unsortedArray, int size) {
	for (int turn = 1; turn < size; turn++) {
		double rememberedValue = unsortedArray[turn];
		int insertionIndex = turn;

		while (insertionIndex >= 1 && unsortedArray[insertionIndex - 1] > rememberedValue) {
			unsortedArray[insertionIndex] = unsortedArray[insertionIndex - 1];
			insertionIndex--;
		}
		unsortedArray[insertionIndex] = rememberedValue;

	}

}  
```  

2.2. Ý tưởng của giải thuật :  

Giải thuật này xuất phát từ các thao tác sắp xếp của những người chơi bài. Tư tưởng đó được thể hiện như sau :   

+ Từ một tập bài gồm n quân bài của người chơi, họ cần phải sắp xếp thứ tự các quân bài trên tay theo một thứ tự tăng dần. Lúc này, họ sẽ duyệt từ quân bài thứ 2 tới quân bài cuối cùng (thứ n). Đối với quân bài thứ 2, họ cần phải so sánh quân bài này với các quân bài phía trước nó, tức lúc này là quân bài thứ 1. Rõ ràng, các quân bài phía trước quân bài thứ 2 đều đã được sắp xếp ( do chỉ có 1 quân bài phía trước). Công việc của người chơi lúc này, là chỉ cần chèn quân bài thứ 2 vào vị trí thích hợp trong số các quân bài phía trước sao cho chúng được sắp xếp theo một thứ tự tăng dần
+ Tiếp tục với việc xét quân bài thứ 3, ta tiến hành so sánh quân bài này với dãy các quân bài đã được sắp xếp ở phía trước nó. Sau đó tiến hành thực hiện thao tác chèn quân bài này vào ví trí thích hợp trong dãy các quân bài phía trước đó, để tạo thành một dãy con được sắp xếp tăng dần.
+ Một cách hoàn toàn tương tự với các quân bài thứ 4, 5 … n. Kết thúc quá trình này, ta sẽ thu được một dãy số được sắp xếp tăng dần  

2.3. Độ phức tạp của thuật toán   

Do đối với mỗi quân bài được lựa chọn, ta đều so sánh nó với các quân bài ở phía trước. Nhìn nhận một các thoải mái trong tình huống xấu nhất, số lần phần duyệt qua các phần tử trong mảng sẽ là : 1 + 2 + … + (n – 1). Có nghĩa độ phức tạp trong tình huống xấu nhất là : O(n^2)  

2.4. Nhận xét và đánh giá  

2.4.1. Ưu điểm :  

- Làm việc tốt trong trường hợp mảng có ít phần tử
- Giải thuật có tính chất ổn định và tại chỗ
- Được sử dụng như một sự hỗ trợ trong một vài giai đoạn con của một vài thuật toán sắp xếp khác
- Đơn giản, dễ hiểu và dễ cài đặt
- Là thuật toán sắp xếp tốt nhất đối với dãy đã gần được sắp xếp , nghĩa là mỗi phần tử đã đứng ở vị trí rất gần vị trí trong thứ tự cần sắp xếp  

2.4.2. Nhược điểm :   

- Độ phức tạp trung bình vẫn còn khá lớn O(n^2) so với các thuật toán sắp xếp nhanh nhất hiện nay như QuickSort  

2.5. Sự tối ưu, so sánh và mở rộng :   

- Thuật toán tuy đã giải quyết được tình huống dãy số đầu vào đã được sắp xếp tăng dần ( tức nó chỉ mất O(n) thời gian sắp xếp). Nhưng còn với trường hợp dãy số đầu vào lại được sắp xếp theo thứ tự giảm dần, trong tình huống này giải thuật vẫn sẽ mất thời gian O(n^2) (thậm chí đây được xếp vào tình huống đầu vào tồi nhất). Để tối ưu giải thuật, xin đề xuất một giải pháp sử dụng biến hasSwapped (như giải pháp tối ưu trong Selection Sort) để phát hiện dãy đầu vào đã được sắp xếp giảm dần, từ đó chỉ cần mất O(n/2) thời gian để đảo ngược dãy số đầu vào đó.
- Một giải pháp tối ưu khá hay được đề xuất tiếp theo đó là : Thay vì trong giai đoạn chèn 1 quân bài vào dãy các quân bài phía trước nó bằng giải pháp tìm kiếm tuần tự, ta sẽ sử dụng giải thuật tìm kiếm nhị phân trong chính quá trình chèn đó. Điều này sẽ giúp tiết kiệm được thời gian tìm kiếm và chèn đi khá đáng kể, từ O(i) xuống còn O(log(i)) với i là chỉ số cần chèn tại đó
- Điều gì sẽ xảy ra nếu giải thuật này được cài bằng danh sách liên kết : Liệu nó sẽ bất lợi hay có lợi? Có nhiều bài toán bắt buộc phải sử dụng việc cài đặt giải thuật Selection Sort bằng cấu trúc dữ liệu Danh sách Liên kết
+ Trong tình huống này, việc sử dụng danh sách liên kết để cài đặt chỉ có lợi khi mà dữ liệu cần sắp xếp đến một cách liên tục (đó có thể là dữ liệu online). Vì vậy, với cách cài đặt Danh sách Liên kết, ta có thể chủ động cấp phát vùng nhớ tùy thích
+ Nhưng khi cài đặt bằng Danh sách liên kết cũng sẽ nảy sinh vài vấn đề : Do việc truy cập vào 1 phần tử trong danh sách liên kết không mang tính trực truy tức phải mất thời gian tuyến tính. Điều này, có thể làm giảm hiệu suất của giải thuật  

Tuy nhiên, trong thực tế để cài đặt Danh sách Liên kết cho giải thuật này, mọi người có thể tham khảo tại đây : 
http://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/

3.Thuật toán Bubble Sort (Sắp xếp nổi bọt)  

3.1. Mã nguồn minh họa : 

```C++
// algorithm for Selection Sort
void bubbleSort(double *unsortedArray, int size) {
	for (int turn = 0; turn < size - 1; turn++) {
		for (int bubbleindex = 0; bubbleindex < size - 1 - turn; bubbleindex++) {
			if (unsortedArray[bubbleindex] > unsortedArray[bubbleindex + 1])
				swap(&unsortedArray[bubbleindex], &unsortedArray[bubbleindex + 1]);
		}
	}
}

Hoặc có thể cài đặt theo cách sau : 
void bubbleSort(double *unsortedArray, int size) {
	for (int turn = size-1; turn > 0; turn--) {
		for (int bubbleIndex = 0; bubbleIndex < turn; bubbleIndex++) {
			if (unsortedArray[bubbleIndex] > unsortedArray[bubbleIndex + 1])
				swap(&unsortedArray[bubbleIndex], &unsortedArray[bubbleIndex + 1]);
		}
	}
}

```

3.2. Ý tưởng của giải thuật : 

Thuật toán này mang một tư tưởng lan truyền, có nghĩa là : với mỗi một quá trình lan truyền (tức một lần duyệt mảng, và quá trình hoán vị liên tiếp hai tử gần kề nếu cần thiết), sau mỗi quá trình “đưa đẩy” và “lan truyền” đó, giải thuật sẽ tìm ra một phần từ lớn nhất rồi cố định nó ở cuối mảng. Lúc này, phần tử ở cuối mảng sẽ không còn đóng bất kỳ một vai trò nào nữa trong quá trình sắp xếp. Khi đó, để dễ hiểu chúng ta có thể giả định, mảng mới chỉ còn lại từ phần từ đầu tiên đến phần từ thứ n – 1 ( không xét phần tử cuối), rồi lại tiến hành quá trình “lan truyền nổi bọt” trong mảng mới này để tiếp tục tìm ra một phần tử lớn nhất và gắn cố định tại trí cuối cùng,,, Cứ như vậy, sau mỗi quá trình lan truyền làm số phần tử trong mảng giảm đi một, và ta lại cố định (hay tìm ra) được một phần tử lớn nhất nằm ở cuối mỗi mảng. Sau n – 1 quá trình lan truyền đó, ta sẽ thu được một mảng đã được sắp xếp và quá trình lan truyền hoàn toàn kết thúc

3.3. Độ phức tạp của giải thuật : 

Do phải trải qua (n-1) quá trình lan truyền, với mỗi quá trình lan truyền sẽ tương ứng với số lần duyệt tối đa qua các phần từ là : (n-1) + (n-2) + … + 1. Vì vậy độ phức tạp của giải thuật trên là : O(n^2)

3.4. Nhận xét và đánh giá : 

3.4.1 Ưu điểm: 

+ Thể hiện được tính ổn định và tại chỗ
+ Đơn giản, dễ hiểu… được sử dụng làm ví dụ minh họa trong quá trình giảng dạy
3.4.2  Nhược điểm :

- Nhược điểm lớn nhất của giải thuật sắp xếp nổi bọt đó là số lần hoán vị quá nhiều so với các giải thuật đã trình bày phía trên. Trong thực tế, giải thuật này hiếm khi được ứng dụng trong các bài toán thực nghiệm. Có nhiều ý kiến cho rằng không nên giảng dạy thuật toán này trong môi trường đại học!

3.5. Tối ưu và so sánh :

- Giải pháp tối ưu cho giải thuật trên đó là sử dụng biến hasSwapped nằm bên ngay trong vòng lặp thứ 2. Nếu đầu vào là đã được sắp xếp thì độ phức thời gian chỉ là O(n). Một cách tương tự, trong trường hợp dãy số đầu được sắp xếp giảm dần

4.	Thuật toán Merge Sort (Sắp xếp trộn)

4.1. Mã nguồn minh họa (python)

```Python
def mergeSort(unsortedList, left, right) :
    if(left < right) :
        middle = int((left + right) / 2)
        mergeSort(unsortedList, left, middle)
        mergeSort(unsortedList, middle + 1, right)
        merge(unsortedList, left, middle, right) # should cast to right type before passing parameters (because default type is float)

		
		
 # Merge two sorted arrays into an root array
def merge(unsortedList, left, middle, right) :
    leftListSize = int(middle - left + 1)
    rightListSize = int(right - middle)

    leftList = leftListSize * [0]
    rightList = rightListSize * [0]

    for index in range(0, leftListSize) :
        leftList[index] = unsortedList[left + index]

    for index in range(0, rightListSize) :
        rightList[index] = unsortedList[middle + 1 + index]

    leftListIndex = 0
    rightListIndex = 0
    mainListIndex = left
    while ((leftListIndex < leftListSize) and (rightListIndex < rightListSize)) :
        if(leftList[leftListIndex] < rightList[rightListIndex]) :
            unsortedList[mainListIndex] = leftList[leftListIndex]
            leftListIndex += 1
        else :
            unsortedList[mainListIndex] = rightList[rightListIndex]
            rightListIndex += 1
        mainListIndex += 1

    if(leftListIndex < leftListSize) :
        for index in range(leftListIndex, leftListSize) :
            unsortedList[mainListIndex] = leftList[index]
            mainListIndex += 1

    if(rightListIndex < rightListSize) :
        for index in range(rightListIndex, rightListSize) :
            unsortedList[mainListIndex] = rightList[index]
            mainListIndex += 1

    del leftList[:]
    del rightList[:]
    
```
    
4.2. Ý tưởng của giải thuật : 

- Sử dụng tư tưởng đệ quy “chia để trị” với quan điểm việc sắp xếp tăng dần một dãy số sẽ tương ứng với các thao tác sau : 

  + Chia dãy số đó làm hai nửa (nửa trái và nửa phải)
  + Thực hiện sắp xếp một cách đệ quy trên từng nửa đó (gọi đệ quy trên nửa trái và nửa phải, hàm gọi đệ quy là mergeSort(…))
  + Mỗi nửa sau khi được sắp xếp sẽ được kết hợp, trộn lẫn với nhau để tạo ra một mảng hoàn chỉnh được sắp xếp tăng dần (sử dụng một hàm trộn merge(…) với đầu vào là 2 mảng đã được sắp xếp, hợp nhất hai mảng này để tạo thành mảng mới đã được sắp xếp)

- Đối với hàm mergeSort(…), điều kiện neo đệ quy là : chỉ số trái left >= chỉ số phải right. Tức tại điểm xảy ra điều kiện neo, lúc này dãy số đã được phân tách nhỏ nhất có thể ( nghĩa là chỉ chứa 1 phần tử), ta gọi các dãy con nhỏ nhất này là các dãy con đơn vị. Lúc này, các dãy con đơn vị đó sẽ đôi một thông qua hàm merge(…) để hợp nhất tạo thành một mảng lớn hơn đã được sắp xếp. Rồi mảng lớn hơn này có thể lại gặp một mảng lớn hơn khác để hợp nhất … Quá trình “hổi quy” này liên tục diễn ra cho tới khi chúng trở về lời gọi của hàm đệ quy gốc, để hợp nhất 2 nửa mảng cuối cùng còn lại và trả về một mảng hoàn chỉnh, đầy đủ và đã được sắp xếp

- Trực quan hình ảnh có thể xem tại link sau : http://www.geeksforgeeks.org/merge-sort/

4.3. Độ phức tạp của giải thuật :

Ta có độ phức tạp của thuật toán :  T(n) = 2T(n/2) + O(n)

Từ công thức trên + áp dụng với Định lý Thợ rút gọn (Trang 48, Sách Cấu trúc dữ liệu và giải thuật, Nguyễn Đức Nghĩa), ta dễ dàng tìm được độ phức tạp của giải thuật trên là : O(n*log(n))

4.4. Nhận xét và đánh giá 

4.4.1 Ưu điểm

- Đơn giản và dễ hiểu, thời gian sắp xếp với độ phức tạp đã được giảm xuống một cách đáng kể (O(nlog(n)) so với các giải thuật Sắp xếp Chèn, Nổi bọt, Chọn
- Giải thuật Sắp xếp Trộn giữ được tính ổn định tương đối của các phần tử

4.4.2. Nhược điểm

- Giải thuật Sắp xếp Trộn do cần phải sử dụng thêm vùng nhớ bên ngoài ( vùng nhớ dùng thêm này tỉ lệ với số lượng phần tử n) nên giải thuật không có tính chất tại chỗ
- Độ phức tạp của giải thuật đều như nhau khi xét trên cả 3 trường hợp : Tốt nhất, Trung bình và Tồi nhất

4.5. Tối ưu thuật toán và các bài toán ứng dụng thực tế

- Một cách tối ưu được để xuất cho giải thuật sắp xếp Trộn đó là sử dụng cấu trúc dữ liệu Danh sách Liên kết thay vì sử dụng mảng. 
  + Bởi vì điểm mạnh của DSLK đó là khả năng đáp ứng một tập dữ liệu đến một cách liên tục (dữ liệu thực tế). Hơn nữa, các thao tác chèn, sửa, xóa một phần tử trong danh sách liên kết chỉ tốn thời gian O(1), nhanh chóng hơn so với thời gian tuyến tính khi chèn, sửa, xóa một phần tử trong mảng. Áp dụng tính chất của DSLK vào giải thuật Sắp xếp Trộn, sẽ giúp tiết kiệm được vùng nhớ ( tức ko cần sử dụng vùng nhớ ngoài – giữ được tính chất “tại chỗ” của giải thuật), đồng thời giải quyết được các bài toán với luồng dữ liệu đến liên tục (online) trong thực tế cuộc sống
  + Sử dụng thêm biến hasSwapped trong từng đoạn nhỏ mảng ( có nghĩa sử dụng điều kiện này kết hợp làm điều kiện neo trong đệ quy), điều này giúp nhanh chóng nhận biết một số đoạn nhỏ trong mảng đã được sắp xếp rồi, từ đó hạn chế được tối đa số bước đệ quy lãng phí tiếp sau. Tương tự cũng nên kiểm tra xem đoạn nhỏ mảng đó có đang là sắp xếp giảm dần (từ đó ta chỉ việc đảo ngược vị trí các phần tử trong mảng). 
- Một số bài toán thực tế có thể áp dụng giải thuật Merge Sort : 
  + Bài toán đếm số đảo ngược :  http://www.geeksforgeeks.org/counting-inversions/
  + Bài toán liên quan tới lĩnh vực sắp xếp tại vùng nhớ ngoài (not sorting in RAM) : https://en.wikipedia.org/wiki/External_sorting







