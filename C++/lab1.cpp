#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

struct fileString {
	std::string value;
	int linenum;
};
fileString *data;

static fileString* merge_sort(fileString *inp, fileString *tmp_a, const int left, const int right) {
	if (left == right) {
		tmp_a[left] = inp[left];
		return tmp_a;
	}

	const int mid = (left + right) / 2;
	const fileString *l_buf = merge_sort(data, tmp_a, left, mid);
	const fileString *r_buf = merge_sort(data, tmp_a, mid + 1, right);

	fileString *result = (l_buf == inp ? tmp_a : inp);

	int l_cur = left, r_cur = mid + 1;
	for (int i = left; i <= right; i++) {
		if (l_cur <= mid && r_cur <= right) {
			if (l_buf[l_cur].linenum < r_buf[r_cur].linenum)
				result[i] = l_buf[l_cur++];
			else
				result[i] = r_buf[r_cur++];
		}
		else if (l_cur <= mid)
			result[i] = l_buf[l_cur++];
		else
			result[i] = r_buf[r_cur++];
	}
	return result;
}

int main(int argc, char *argv[]) {
	int tr = clock();
	std::ios::sync_with_stdio(false);
	if (argc != 3) return 1;
	std::ifstream ifile(argv[1]);
	std::ofstream ofile(argv[2]);
	if (!ifile.is_open() || !ofile.is_open()) return 2;

	std::string line;
	getline(ifile, line);
	try {
		stoi(line);
	}
	catch (...) {
		return 3;
	}
	const int num = stoi(line);
	int tv = clock();
	data = new fileString[num];
	tv = clock() - tv;
	fileString *tmp = new fileString[num];
	int counter = 0;
	try {
		for (counter; getline(ifile, line); counter++) {
			data[counter].linenum = stoi(line.substr(0, line.find(' ')));
			data[counter].value = (' ' + line.substr(line.find(' ') + 1));
		}
	}
	catch (...) {
		return 3;
	}
	ifile.close();
	tr = clock() - tr;
	int ts = clock();
	data = merge_sort(data,tmp,0,num-1);
	ts = clock() - ts;
	int tw = clock();
	ofile << num;
	for (counter = 0; counter < num; counter++)
		ofile << "\n" << data[counter].linenum << data[counter].value;

	ofile.close();
	tw = clock() - tw;
	std::cout << "R:" << tr << "ms S:" << ts << "ms W:" << tw << "ms RSW:" << tr + ts + tw << "ms Allocating:" << tv;
	return 0;
}
