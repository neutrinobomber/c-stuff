#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <iomanip>
#include <array>
#include <tuple>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

const int MaxMoves = 8;

class Board
{
private:
	array<pair<int, int>, MaxMoves> moves;
	int size;
	vector<vector<int>> data;
public:
	Board(int size) : size(size), data(size)
	{
		for (int i = 0; i < this->size; i++)
		{
			data[i].resize(size);
		}

		moves[0] = make_pair(2, 1);
		moves[1] = make_pair(1, 2);
		moves[2] = make_pair(-1, 2);
		moves[3] = make_pair(-2, 1);
		moves[4] = make_pair(-2, -1);
		moves[5] = make_pair(-1, -2);
		moves[6] = make_pair(1, -2);
		moves[7] = make_pair(2, -1);
	}

	array<int, MaxMoves> SortMoves(int x, int y) const
	{
		array<tuple<int, int>, MaxMoves> counts;
		for (int i = 0; i < MaxMoves; ++i)
		{
			int dx = get<0>(moves[i]);
			int dy = get<1>(moves[i]);

			int c = 0;
			for (int j = 0; j < MaxMoves; ++j)
			{
				int x2 = x + dx + get<0>(moves[j]);
				int y2 = y + dy + get<1>(moves[j]);

				if (x2 < 0 || x2 >= this->size || y2 < 0 || y2 >= this->size)
				{
					continue;
				}

				if (data[y2][x2] != 0)
				{
					continue;
				}

				c++;
			}

			counts[i] = make_tuple(c, i);
		}

		random_shuffle(counts.begin(), counts.end());

		sort(counts.begin(), counts.end());

		array<int, MaxMoves> out;
		for (int i = 0; i < MaxMoves; ++i)
		{
			out[i] = get<1>(counts[i]);
		}

		return out;
	}

	void Reset()
	{
		for (int v = 0; v < this->size; ++v)
		{
			for (int u = 0; u < this->size; ++u)
			{
				data[v][u] = 0;
			}
		}
	}

	void Solve(int startX, int startY)
	{
		this->Reset();

		int x0 = startX - 1;
		int y0 = this->size - startY;
		this->data[y0][x0] = 1;

		vector<tuple<int, int, int, array<int, MaxMoves>>> order(this->size * this->size);
		order[0] = make_tuple(x0, y0, 0, SortMoves(x0, y0));

		int n = 0;
		while (n < this->size * this->size - 1)
		{
			int x = get<0>(order[n]);
			int y = get<1>(order[n]);

			bool solved = false;
			for (int i = get<2>(order[n]); i < 8; ++i)
			{
				int dx = this->moves[get<3>(order[n])[i]].first;
				int dy = this->moves[get<3>(order[n])[i]].second;

				if (x + dx < 0 || x + dx >= this->size || y + dy < 0 || y + dy >= this->size)
				{
					continue;
				}

				if (this->data[y + dy][x + dx] != 0)
				{
					continue;
				}

				++n;
				get<2>(order[n]) = i + 1;
				this->data[y + dy][x + dx] = n + 1;
				order[n] = make_tuple(x + dx, y + dy, 0, this->SortMoves(x + dx, y + dy));
				solved = true;
				break;
			}

			if (!solved)
			{
				this->Reset();
				this->data[y][x] = 0;
				--n;
			}
		}
	}

	friend ostream& operator<<(ostream& out, const Board& b);
};

ostream& operator<<(ostream& out, const Board& b)
{
	for (int i = 0; i < b.size; ++i)
	{
		for (int j = 0; j < b.size; ++j)
		{
			out << setw(3) << b.data[i][j];
		}
		out << endl;
	}

	return out;
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream is{ line };
		
		int boardSize = 0;
		int startX = 0;
		int startY = 0;
		is >> boardSize >> startX >> startY;

		Board board(boardSize);
		board.Solve(startX, startY);
		cout << board << endl;
	}

	return 0;
}
