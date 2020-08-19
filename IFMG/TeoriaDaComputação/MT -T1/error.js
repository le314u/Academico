module.exports = class Error {
    constructor(name="Nome genérico", condition="Condição não especificada", extra={}){
        throw `Erro:\nTipo de erro: ${name}\nCausa: ${condition}`
    }
}