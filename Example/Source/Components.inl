// Components

using TimeType = int;

struct Position {
    int x { 0 };
    int y { 0 };
};

using Orientation = float;

struct InitialPosition : Position {};
struct StartPosition : Position {};

struct Size : Position {};
struct InitialSize : Size {};

using Index = unsigned int;

struct Preselected {};
struct Selected {};
struct Hovered {};

using Color = ImVec4;

struct Name {
    const char* text;
};

// Input

// From e.g. Wacom tablet
struct InputPressure  { float strength; };
struct InputPitch  { float angle; };
struct InputYaw  { float angle; };

// From e.g. Mouse or WASD keys
struct InputPosition2D {
    Vector2i absolute;
    Vector2i relative;
    Vector2i delta;
};

struct InputPosition3D : Vector3i {
    using Vector3i::Vector3i;
};

// From e.g. WASD keys or D-PAD on XBox controller
enum class Direction2D : std::uint8_t { Left = 0, Up, Right, Down };
enum class Direction3D : std::uint8_t { Left = 0, Up, Right, Down, Forward, Backward };


// Math

inline Position operator*(const Position& pos, const Position other) {
    return Position{ pos.x * other.x, pos.y * other.y };
}

inline Position operator+(const Position& pos, const Position other) {
    return Position{ pos.x + other.x, pos.y + other.y };
}

inline Position operator-(const Position& pos, const Position other) {
    return Position{ pos.x - other.x, pos.y - other.y };
}

// inline operator Position::Vector2i() const { return { x, y };}