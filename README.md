# electron-webpack-quick-start and a native module
>This is a kind of fork of the bare minimum project structure to get started developing with [`electron-webpack`](https://github.com/electron-userland/electron-webpack).

## Getting Started
Simply clone down this reposity, install dependencies, and get started on your application.

The use of the [yarn](https://yarnpkg.com/) package manager is **strongly** recommended, as opposed to using `npm`.


### Development Scripts

```bash
# run application in development mode
yarn dev

# compile the native module and link the new module
yarn install

# compile source code and create webpack output
yarn compile

# `yarn compile` & create build with electron-builder
yarn dist

# `yarn compile` & create unpacked build with electron-builder
yarn dist:dir
```
