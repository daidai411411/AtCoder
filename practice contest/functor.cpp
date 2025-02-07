#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

using namespace std;

// ファンクタ
struct GetLength {
	size_t operator()(string s) {
		return s.length();
	}
};

// ファンクタをテンプレートで受け取り、自らのメンバ関数の中で実行するクラス
template <class Functor>
class Temp {
   private:
	Functor functor;

   public:
	void CallFunctor(string s) {
		cout << s << " : " << functor(s) << endl;
	}
};

int main() {
	// ファンクタを実行
	GetLength get_length;
	cout << "hello : " << get_length("hello") << endl;

	// ファンクタをテンプレートでクラスのインスタンスに渡し、そのインスタンスのメンバ関数を通じてファンクタを実行
	Temp<GetLength> temp;
	temp.CallFunctor("bye");

	return 0;
}
