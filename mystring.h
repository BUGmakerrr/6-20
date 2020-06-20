#include<assert.h>
#include<string>

namespace Frish{
	class string{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		~string(){
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		void reserve(size_t n){
			if (n > _capacity)
			{
				char* newstr = new char[n + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0'){
			if (n < _size){
				_str[n] = '\0';
				_size = n;
			}
			else{
				if (n > _capacity){
					reserve(n);
				}

				for (size_t i = _size; i < n; ++i){
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}
		void insert(size_t pos, const char* str){
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len > _capacity){
				reserve(_size + len);
			}
			int end = _size;
			while (end >= pos){
				_str[end + len] = _str[end];
				--end;
			}
			/*for (size_t n = pos; n < (pos + len); ++n){
				size_t i = 0;
				_str[n] = str[i];
				++i;
			}*/
			for (size_t i = 0; i < len; ++i){
				_str[len]
			}
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;



	};
}