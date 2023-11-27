#include "gtest/gtest.h"
#include "pch.h"
std::string determineTriangleType(int side1, int side2, int side3) {
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return "Invalido";
    }
    else if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        return "Invalido";
    }
    else if (side1 == side2 && side2 == side3) {
        return "Equilatero";
    }
    else if (side1 == side2 || side1 == side3 || side2 == side3) {
        return "Isosceles";
    }
    else {
        return "Escaleno";
    }
}

class TriangleTypeFixture : public ::testing::Test {
protected:
    int* dynamicMemory;

    void SetUp() override {
        dynamicMemory = new int(10); // Simulación de asignación de memoria
    }

    void TearDown() override {
        delete dynamicMemory; // Liberación de memoria
    }
};

TEST_F(TriangleTypeFixture, Equilatero) {
    ASSERT_EQ(determineTriangleType(*dynamicMemory, *dynamicMemory, *dynamicMemory), "Equilatero");
}

TEST_F(TriangleTypeFixture, Isosceles) {
    ASSERT_EQ(determineTriangleType(*dynamicMemory + 2, *dynamicMemory + 2, *dynamicMemory), "Isosceles");
}

TEST_F(TriangleTypeFixture, Escaleno) {
    ASSERT_EQ(determineTriangleType(*dynamicMemory, *dynamicMemory + 1, *dynamicMemory + 2), "Escaleno");
}

TEST_F(TriangleTypeFixture, LadosCero) {
    ASSERT_EQ(determineTriangleType(0, 0, 0), "Invalido");
}

TEST_F(TriangleTypeFixture, LadosNegativos) {
    ASSERT_EQ(determineTriangleType(-3, -4, -5), "Invalido");
}

TEST_F(TriangleTypeFixture, UnLadoCero) {
    ASSERT_EQ(determineTriangleType(0, 3, 4), "Invalido");
}

TEST_F(TriangleTypeFixture, TodosLadosIgualesNegativos) {
    ASSERT_EQ(determineTriangleType(-2, -2, -2), "Invalido");
}

TEST_F(TriangleTypeFixture, TrianguloEquilateroGrande) {
    ASSERT_EQ(determineTriangleType(10000, 10000, 10000), "Equilatero");
}

TEST_F(TriangleTypeFixture, TrianguloEscalenoGrande) {
    ASSERT_EQ(determineTriangleType(123456, 789012, 345678), "Invalido");
}

TEST_F(TriangleTypeFixture, UnLadoEnorme) {
    ASSERT_EQ(determineTriangleType(2147483647, 5, 5), "Invalido");
}

TEST_F(TriangleTypeFixture, TodosLadosEnormes) {
    ASSERT_EQ(determineTriangleType(2147483647, 2147483647, 2147483647), "Invalido");
}

TEST_F(TriangleTypeFixture, SumaDosLadosMayor) {
    ASSERT_EQ(determineTriangleType(3, 4, 8), "Invalido");
}

TEST_F(TriangleTypeFixture, SumaDosLadosIgual) {
    ASSERT_EQ(determineTriangleType(3, 4, 7), "Invalido");
}
