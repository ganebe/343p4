#ifndef MOVIE_H_
#define MOVIE_H_
#include <string>
#include <sstream>

using namespace std;

class Movie {
public:

    // Constructor	
    Movie(int stock, const string& director, const string& title);

    // Virtual destructor
    virtual ~Movie() = default;

    // get stock
    int getStock() const;

    // set stock
    void setStock(int stock);

    // get current stock
    int getCurrentStock()const;

    // get director
    const string& getDirector() const;
    // get title
    const string& getTitle() const;

    // borrowing and returning functions
    bool borrowMovie();
    bool returnMovie();

    // Comparison operators
    virtual bool operator==(const Movie& other) const;
    virtual bool operator!=(const Movie& other) const;
	virtual bool operator<(const Movie& other) const;
	virtual bool operator>(const Movie& other) const;
private:
    int current_stock_; // Number of stock available.
    int stock_; // Number of stock.
    string director_, title_; // Director of the movie and title of the movie.
};
#endif
