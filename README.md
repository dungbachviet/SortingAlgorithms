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


