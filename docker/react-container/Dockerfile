FROM node:latest

WORKDIR /build

COPY package.json package-lock.json /build

RUN npm ci

COPY . /build

RUN npm run build

FROM nginx:1.25-alpine3.18-perl

WORKDIR /app

COPY --from=0 /build/build /usr/share/nginx/html




