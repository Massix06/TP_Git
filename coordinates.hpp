//
// Created by nassim on 25/05/23.
//

#ifndef OPENXUM_WS_CPP_COORDINATES_HPP
#define OPENXUM_WS_CPP_COORDINATES_HPP

#include <nlohmann/json.hpp>
#include <iostream>

namespace openxum::core::games::yavalax {
    class Coordinates {
    public:

        explicit Coordinates(int = 0, int = 0);

        bool is_valid() {

            if (_line >= 0 && _line < 13 && _column >= 0 && _column < 13) {
                return true;
            } else {
                return false;
            }
        };

        std::pair<int, int> clone(int line, int column) {
            return clone(line, column);
        };


        int get_column() const {
            return _column;
        };

        int get_line() const {
            return _line;
        };

        bool equals(Coordinates c) {
            if (c.get_column() == _column && c.get_line() == _line) {
                return true;

            } else {
                return false;
            };
        };

        void from_object(const nlohmann::json &json) {
            _column = json["colomn"].get<int>();
            _line = json["line"].get<int>();
        };

        std::string to_string() {
            if (!is_valid()) { return "invalid coordinates"; }
            return std::to_string(_column) + std::to_string(_line);
        }

        //void to_object(const){};
        nlohmann::json to_object() const {
            nlohmann::json json;

            json["line"] = _line;
            json["column"] = _column;
            return json;
        }

    private:
        int _column;
        int _line;

    };
}

#endif //OPENXUM_WS_CPP_COORDINATES_HPP