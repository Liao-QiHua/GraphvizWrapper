// The MIT License (MIT)

// Copyright (c) 2024 Liao-QiHua

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#include <iostream>
#include "include/html_like.h"

int test0() {
    using namespace std;
    using namespace graphvizwrapper::htmllike;
    Table * table = new Table;
    table->SetAlign("center");

    TableRow * row1 = new TableRow;
    TableRow * row2 = new TableRow;
    row1->SetAlign("left");
    row1->SetBgcolor("green");
    TableCell * cell11 = new TableCell;
    cell11->SetText(std::string("A"));
    TableCell * cell12 = new TableCell;
    cell12->SetText(std::string("B"));
    row1->AddCell(cell11);
    row1->AddCell(cell12);
    TableCell * cell21 = new TableCell;
    cell21->SetText(std::string("C"));
    row2->AddCell(cell21);
    table->AddRow(row1);
    table->AddRow(row2);
    std::cout << table->to_string() << "\n";
    return 0;
}

int main() {
    return test0();
}
