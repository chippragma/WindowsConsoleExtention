#ifndef PROJECT_BORDER_H
#define PROJECT_BORDER_H

#include <string>
#include <map>

namespace cpe::ui::style {

enum class DualBorder;

class Border {
public:
    /**
     * Сторона (позиция) рамки
     */
    static enum Side {
        /** Левая сторона */
        L,
        /** Правая сторона */
        R,
        /** Верхняя сторона */
        T,
        /** Нижняя сторона */
        B,
        /** Левый-верхний угол */
        LT,
        /** Правый-верхний угол */
        RT,
        /** Левый-нижний угол */
        LB,
        /** Правый-нижний угол */
        RB,
        /** Вертикальная внутренняя */
        V,
        /** Горизонтальная внутренняя */
        H,
        /** Вертикальный-левый тройник */
        VL,
        /** Вертикальный-правй тройник */
        VR,
        /** Горизонтальный-верхний тройник */
        HT,
        /** Горизонтальный-нижний тройник*/
        HB,
        /** Внутреннее перекрестие */
        C
    };

    Border();

    /**
     * Создает и сразу применяет стиль рамок
     * @param dualBorder Стиль рамок
     */
    explicit Border(const DualBorder &dualBorder);

    /**
     * Применяет новую настройку стиля рамок, по которому назначаются символы рамки
     * @param dualBorder Стиль рамок
     */
    void apply(const DualBorder &dualBorder);

    const std::wstring &operator [](const Side&& side) const;

private:
    std::map<Side, std::wstring> _sides;
};

}

#endif //PROJECT_BORDER_H