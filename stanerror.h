// basic error handling and stopping program in case of something
// will go terribly wrong aka I fuck something up;
#ifndef         __STANERROR_H
#define         __STANERROR_H

namespace stan {
    class error {
        public:
            explicit error() noexcept;
            explicit error(
                const char* error
            ) noexcept;
            explicit error(
                char error[]
            ) noexcept;

    };

}

#endif